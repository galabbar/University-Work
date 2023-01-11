/*
  adminRawMedicne.js
  Hassan Khalaf - 2192131028
  Phase 3
*/
// save all charts here.
let arrayOfCharts = [];
// define the container of the raw material
let container = document.getElementById("RawMaterialRow");
function start() {
  console.log("Hello World");

  //nav tool tips enabling
  var tooltipTriggerList = [].slice.call(
    document.querySelectorAll('[data-bs-toggle="tooltip"]')
  );
  tooltipTriggerList.map(function (tooltipTriggerEl) {
    return new bootstrap.Tooltip(tooltipTriggerEl);
  });

  // define the container of the raw material
  container = document.getElementById("RawMaterialRow");

  let result = 0;
  //add to database
  if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
  } else {
    // code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.open("GET", `./php/adminRawSelect.php`, false);
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = JSON.parse(xmlhttp.responseText);
  }
  // load from data base the data and set them
  let countRawMaterial = result.length - 1;

  // load items to page
  for (var i = 0; i < countRawMaterial; i++) {
    add(
      result[i].id,
      result[i].name,
      result[i].available,
      result[i].used,
      result[i].img
    );
  }
}

// add new material
function add(
  id,
  nameRawMaterial,
  totalRawMaterial,
  usedRawMaterial,
  sourceOfPic
) {
  // define the new element of the material
  let newElement = document.createElement("div");
  newElement.id = "rawMaterialElement" + id;
  newElement.classList = "col-md-3 mb-3 car";
  newElement.setAttribute("name", nameRawMaterial);
  newElement.innerHTML = `
              <!-- Item -->
                <div class="card bg-white p-3 shaddow overflow-hidden" >
                  <h6 class="text-center my-3">${nameRawMaterial}</h6>
                  <img src="${sourceOfPic}" alt="${nameRawMaterial}"/>
                  <canvas id="rawMaterial${id}"></canvas>
                  <div class="d-flex justify-content-between align-items-center mt-4">
                    <button class="btn btn-sm btn-outline-primary" onclick="deleteM(${id} , '${nameRawMaterial}');">Delete</button>
                    <button class="btn btn-sm btn-primary" onclick="modify(${id});">Modify</button>
                  </div>
                </div>
            `;

  // add it to the page
  container.append(newElement);

  // config the chart of it
  const config = {
    type: "doughnut",
    data: {
      labels: ["Not Used", "Used"],
      datasets: [
        {
          label: "Dataset 1",
          data: [parseInt(totalRawMaterial), parseInt(usedRawMaterial)],
          backgroundColor: ["grey", "#f2545b"],
        },
      ],
    },
    options: {
      plugins: {
        legend: {
          position: "top",
        },
      },
    },
  };
  // load the chart
  arrayOfCharts.push(
    new Chart(document.getElementById("rawMaterial" + id), config)
  );
}

// delete a raw material
function deleteM(id, name) {
  // get confirmation
  Swal.fire({
    title: "Are you sure?",
    text: "You won't be able to revert this!",
    icon: "error",
    showCancelButton: true,
    confirmButtonColor: "#d33",
    cancelButtonColor: "#19323c",
    confirmButtonText: "Yes, delete it!",
  }).then((result) => {
    // if confirmed, delete and let the user know
    if (result.isConfirmed) {
      let result = 0;
      //add to database
      if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();
      } else {
        // code for IE6, IE5
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
      }

      xmlhttp.open("GET", `./php/adminRawDelete.php?id=${id}`, false);
      xmlhttp.send(null);
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        result = JSON.parse(xmlhttp.responseText);
      }

      // load to page
      if (result == 1) {
        document.getElementById("rawMaterialElement" + id).remove();

        Swal.fire(
          "Deleted!",
          "You deleted the raw material " + name + ", ID: " + id,
          "success"
        );
      } else {
        Swal.fire("Error!", "Something went wrong" + result, "error");
      }
    }
  });
}
var myModal = new bootstrap.Modal(document.getElementById("addModal"), {
  keyboard: true,
});

// open the modal, reset the information
function openModal() {
  myModal.toggle();
  idOfNewComp = 0;
  document.getElementById("formNewMName").value = "";
  document.getElementById("formNewMQuantity").value = "";
  document.getElementById("formNewMPic").value = "";
  document.getElementById("formNewMNameHelp").classList.add("d-none");
  document.getElementById("formNewMQuantityHelp").classList.add("d-none");
  document.getElementById("formNewMPicHelp").classList.add("d-none");
  document.getElementById("formNewMHelp").classList.add("d-none");
}

// load new raw material to page
function addNew() {
  // get the main information
  let name = document.getElementById("formNewMName");
  let quan = document.getElementById("formNewMQuantity");
  let pic = document.getElementById("formNewMPic");

  let flag = false;
  if (!name.value || !quan.value || !pic.value) {
    document.getElementById("formNewMHelp").classList.remove("d-none");
    document.getElementById("formNewMQuantityHelp").classList.remove("d-none");
    document.getElementById("formNewMPicHelp").classList.remove("d-none");
    document.getElementById("formNewMNameHelp").classList.remove("d-none");
    flag = true;
  } else {
    document.getElementById("formNewMNameHelp").classList.add("d-none");
    document.getElementById("formNewMHelp").classList.add("d-none");
    document.getElementById("formNewMQuantityHelp").classList.add("d-none");
    document.getElementById("formNewMPicHelp").classList.add("d-none");
  }
  if (flag) return;

  let result = 0;
  //add to database
  if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
  } else {
    // code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.open(
    "GET",
    `./php/adminRawInsert.php?name=${name.value}&pic=${pic.value}&qty=${quan.value}`,
    false
  );
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = xmlhttp.responseText;
  }

  // load to page
  if (result == 1) {
    add(arrayOfCharts.length + 1, name.value, quan.value, 0, pic.value);
    Swal.fire("Done!", "New Raw Material added", "success");
    myModal.toggle();
  } else {
    Swal.fire("Error!", "Something went wrong" + result, "error");
    myModal.toggle();
  }
}

// modify raw material
async function modify(id) {
  // enter the number
  const { value: number } = await Swal.fire({
    title: "Enter your weight",
    input: "text",
    inputPlaceholder: "If +ve will increase, if -ve will decrease,",
    inputAttributes: {
      maxlength: 10,
      autocapitalize: "off",
      autocorrect: "off",
    },
  });
  // if null return
  if (!number) return;
  if (isNaN(number)) {
    Swal.fire("Error", "You must enter a number", "error");
    return;
  }

  // get confirmation
  Swal.fire({
    title: "Are you sure?",
    text: "You won't be able to revert this!",
    icon: "error",
    showCancelButton: true,
    confirmButtonColor: "#d33",
    cancelButtonColor: "#19323c",
    confirmButtonText: "Yes, Modify it!",
  }).then((result) => {
    // if confirmed, modify and let the user know
    if (result.isConfirmed) {
      // get the old data
      let oldData = arrayOfCharts[id - 1].data.datasets[0].data;
      if (oldData[0] + parseInt(number) < 0) {
        //compare old data with new
        Swal.fire("Warning", "Total will be under zero!", "warning");
        return;
      }

      let result = 0;
      //add to database
      if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();
      } else {
        // code for IE6, IE5
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
      }

      xmlhttp.open(
        "GET",
        `./php/adminRawUpdate.php?id=${id}&update=${
          oldData[0] + parseInt(number)
        }`,
        false
      );
      xmlhttp.send(null);
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        result = JSON.parse(xmlhttp.responseText);
      }

      // load to page
      if (result == 1) {
        // update the chart
        arrayOfCharts[id - 1].data.datasets[0].data = [
          oldData[0] + parseInt(number),
          oldData[1],
        ];
        arrayOfCharts[id - 1].update();
        Swal.fire("Done!", "You the total modified by " + number, "success");
      } else {
        Swal.fire("Error!", "Something went wrong" + result, "error");
      }
    }
  });
}

// filter function
function filter() {
  // get the search input
  let search = document.getElementById("search");
  // get all cards in page
  let cards = document.getElementsByClassName("car");
  // show cards if search value is empty
  if (search.value == "") {
    for (var i = 0; i < cards.length; i++) {
      cards[i].style.display = "";
    }
    return;
  }
  // if not empty, check the name, if not equal or not their, hide, if their, show
  for (var i = 0; i < cards.length; i++) {
    let res = cards[i].getAttribute("name").toLowerCase();
    if (res == "" || res == null) {
      cards[i].style.display = "none";
      return;
    }
    if (!res.includes(search.value.toLowerCase()))
      cards[i].style.display = "none";
    else cards[i].style.display = "";
  }
}

// on load page
window.addEventListener("load", start, false);
