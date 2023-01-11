/*
  chemist.js
  Hassan Khalaf - 2192131028
  Phase 3
*/
// define the container of the raw material
let container = document.getElementById("medicineList");
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
  container = document.getElementById("medicineList");
  // load from data base the data and set them
  // these infromation are fixed for testing
  let result = 0;
  //add to database
  if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
  } else {
    // code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.open("GET", `./php/chemistMedSelect.php`, false);
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    console.log(xmlhttp.responseTex);
    result = JSON.parse(xmlhttp.responseText);
  }

  let countMedicne = result.length - 1;
  // load items to page
  for (var i = 0; i < countMedicne; i++) {
    add(
      result[i].id,
      result[i].name,
      result[i].desc,
      result[i].img,
      result[i].qty,
      result[i].weight,
      result[i].comb,
      result[i].count,
      result[i].making
    );
  }
}

function add(
  id,
  nameMedicne,
  descriptionMedicne,
  imgMedicne,
  medicineStock,
  combinationMedicne,
  combinationMedicneKeys,
  count,
  making
) {
  // define the list
  let newList = document.createElement("ul");
  for (var k = 0; k < combinationMedicneKeys.length; k++) {
    newList.innerHTML += `
          <li>
            ${
              combinationMedicneKeys[k] +
              ": " +
              combinationMedicne[combinationMedicneKeys[k]]
            }
          </li>
        `;
  }
  // define the new element of the material
  let newElement = document.createElement("div");
  newElement.id = "MedicneElement" + id;
  newElement.classList = "col-md-3 mb-3 car";
  newElement.setAttribute("name", nameMedicne);
  newElement.innerHTML = `
            <!-- item -->
              <div class="card bg-white p-0 shadow overflow-hidden">
                <!-- img -->
                <img src="${imgMedicne}" alt="${nameMedicne}" />
                <!-- details -->
                <div class="p-3">
                  <h5>${nameMedicne}</h5>
                  <p>Stock: <span id="MedicneStock${id}">${medicineStock}</span></p>
                  <p class="text-muted">${descriptionMedicne}</p>
                  <h6>Combination:</h6>
                  ${newList.outerHTML}
                  <!-- action button -->
                  <div class="text-end" id="make${id}">
                    <button class="btn btn-sm btn-outline-primary" onclick="make(${id})">Make</button>
                  </div>
                </div>
              </div>
            `;

  // add it to the page
  container.append(newElement);
  if (parseInt(count) > 0) {
    let btns = document.getElementById("make" + id);
    btns.innerHTML = `
    <div class="text-start">
      <h6><span class="badge bg-info">Making <span id="MedMaking${id}">${making}</span></span></h6>
    </div>
    <button class="btn btn-sm btn-secondary" onclick="done(${id})">Done</button>
    <button class="btn btn-sm btn-outline-secondary" onclick="modify(${id})">Modify</button>
    <button class="btn btn-sm btn-primary" onclick="cancel(${id})">Cancel</button>
  `;
  }
}

window.addEventListener("load", start, false);

async function modify(id) {
  // enter the number
  const { value: number } = await Swal.fire({
    title: "Enter your quantity",
    input: "number",
    inputPlaceholder: "Enter how many do you want to max",
    inputAttributes: {
      maxlength: 4,
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

  if (number <= 0) {
    Swal.fire("Error", "You must enter a postive number", "error");
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
    `./php/chemistMedUpdate.php?id=${id}&qty=${parseInt(number)}`,
    false
  );
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = xmlhttp.responseText;
  }

  // load to page
  if (result == 1) {
    Swal.fire("Done!", "", "success");
    document.getElementById(`MedMaking${id}`).innerText = number;
  } else {
    Swal.fire("Error!", "Something went wrong" + result, "error");
  }
}
// make function
async function make(id) {
  // enter the number
  const { value: number } = await Swal.fire({
    title: "Enter your quantity",
    input: "number",
    inputPlaceholder: "Enter how many do you want to max",
    inputAttributes: {
      maxlength: 4,
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

  if (number <= 0) {
    Swal.fire("Error", "You must enter a postive number", "error");
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
    `./php/chemistMakeInsert.php?id=${id}&qty=${parseInt(number)}`,
    false
  );
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = xmlhttp.responseText;
  }

  // load to page
  if (result == 1) {
    // update the chart
    // replace the buttons
    let btns = document.getElementById("make" + id);
    btns.innerHTML = `
    <div class="text-start">
      <h6><span class="badge bg-info">Making <span id="MedMaking${id}">${number}</span></span></h6>
    </div>
    <button class="btn btn-sm btn-secondary" onclick="done(${id})">Done</button>
    <button class="btn btn-sm btn-outline-secondary" onclick="make(${id})">Modify</button>
    <button class="btn btn-sm btn-primary" onclick="cancel(${id})">Cancel</button>
  `;
    Swal.fire("Done!", "", "success");
  } else {
    Swal.fire("Error!", "Something went wrong" + result, "error");
  }
}

function cancel(id) {
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
      let result = 0;
      //add to database
      if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();
      } else {
        // code for IE6, IE5
        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
      }

      xmlhttp.open("GET", `./php/chemistMakeCancel.php?id=${id}`, false);
      xmlhttp.send(null);
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        result = xmlhttp.responseText;
      }

      // load to page
      if (result == 1) {
        // replace the buttons
        let btns = document.getElementById("make" + id);
        btns.innerHTML = `
        <button class="btn btn-sm btn-outline-primary" onclick="make(${id})">Make</button>
      `;
        Swal.fire("Done!", "Canceled..", "success");
      } else {
        Swal.fire("Error!", "Something went wrong" + result, "error");
      }
    }
  });
}

function done(id) {
  // get confirmation
  Swal.fire({
    title: "Are you sure it is done?",
    text: "You won't be able to revert this!",
    icon: "error",
    showCancelButton: true,
    confirmButtonColor: "#d33",
    cancelButtonColor: "#19323c",
    confirmButtonText: "Yes, Modify it!",
  }).then((result) => {
    // if confirmed, modify and let the user know
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

      xmlhttp.open("GET", `./php/chemistMakeDone.php?id=${id}`, false);
      xmlhttp.send(null);
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        result = xmlhttp.responseText;
      }

      // load to page
      if (result == 1) {
        // replace the buttons
        let btns = document.getElementById("make" + id);
        let stock = document.getElementById("MedicneStock" + id);
        let making = document.getElementById("MedMaking" + id);
        stock.innerHTML =
          parseInt(stock.innerText) + parseInt(making.innerText);
        btns.innerHTML = `
        <button class="btn btn-sm btn-outline-primary" onclick="make(${id})">Make</button>
      `;
        Swal.fire("Done!", "Added to Stock..", success);
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
