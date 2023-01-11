/*
  chemistMaterial.js
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
  // these infromation are fixed for testing
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
                <div class="card bg-white p-3 shaddow overflow-hidden" id="card${id}">
                  <h6 class="text-center my-3">${nameRawMaterial}</h6>
                  <img src="${sourceOfPic}" alt="${nameRawMaterial}"/>
                  <canvas id="rawMaterial${id}"></canvas>
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
        title: {
          display: true,
          text: nameRawMaterial,
        },
      },
    },
  };
  // load the chart
  arrayOfCharts.push(
    new Chart(document.getElementById("rawMaterial" + id), config)
  );
}

// on load page
window.addEventListener("load", start, false);

// filter function
function filter() {
  // get the search input
  let search = document.getElementById("search");
  // get all cards in page
  let cards = document.getElementsByClassName("card");
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
