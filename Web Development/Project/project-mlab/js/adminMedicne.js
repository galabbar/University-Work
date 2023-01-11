/*
  adminMedicne.js
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
  let result = 0;
  //add to database
  if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
  } else {
    // code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.open("GET", `./php/adminMedSelect.php`, false);
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
      result[i].comb
    );
  }
}

// add functions to load single item to page
function add(
  id,
  nameMedicne,
  descriptionMedicne,
  imgMedicne,
  medicineStock,
  combinationMedicne,
  combinationMedicneKeys
) {
  // define the list of copms
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
              <div class="card bg-white p-0 shadow overflow-hidden" ">
                <!-- img -->
                <img src="${imgMedicne}" alt="${nameMedicne}" />
                <!-- details -->
                <div class="p-3">
                  <h5>${nameMedicne}</h5>
                  <p>Stock: ${medicineStock}</p>
                  <p class="text-muted">${descriptionMedicne}</p>
                  <h6>Combination:</h6>
                  ${newList.outerHTML}
                  <!-- action button -->
                  <div class="d-flex justify-content-between align-items-center mt-4">
                    <button class="btn btn-sm btn-outline-primary" onclick="deleteM(${id}, '${nameMedicne}');">Delete</button>
                    <button class="btn btn-sm btn-primary" onclick="modify(${id});">Modify</button>
                  </div>
                </div>
              </div>
            `;

  // add it to the page
  container.append(newElement);
}

// id of new comp for modal
let idOfNewComp = 0;

function modify(id) {
  let result = 0;
  //add to database
  if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    xmlhttp = new XMLHttpRequest();
  } else {
    // code for IE6, IE5
    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
  }

  xmlhttp.open("GET", `./php/adminMedSelect2.php?id=${id}`, false);
  xmlhttp.send(null);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = JSON.parse(xmlhttp.responseText);
    console.log(result);
  }
}
// remove comp from modal
function removeComp() {
  if (idOfNewComp == 0) return;
  document.getElementById("comp" + idOfNewComp).remove();
  idOfNewComp--;
}
//add new comp for modal
function addComp() {
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

  if (!result) return;
  var options = "";
  for (var i = 0; i < result.length - 1; i++) {
    options += `<option value='${result[i].id}'>${result[i].name}</option>`;
  }

  idOfNewComp++;

  //add a row, div by 2, the first is select for comp, the second us number for quantity
  document.getElementById("newFormCom").innerHTML += `
  <div class="row mt-3" id="comp${idOfNewComp}">
    <hr /> 
    <div class="col-6">
      <label for="formNewSelectComp${idOfNewComp}">Select Component</label>
      <select id="formNewSelectComp${idOfNewComp}" name="formNewSelectComp${idOfNewComp}" class="form-control" required>
        <option disabled selected> Select Component</option>
        ${options}
      </select>
    </div>
    <div class="col-6">
      <label for="formNewSelectCompQ${idOfNewComp}">Enter quantity</label>
      <input
        type="number"
        name="formNewSelectCompQ${idOfNewComp}"
        id="formNewSelectCompQ${idOfNewComp}"
        class="form-control"
        placeholder="enter quantity here"
        required
      />
    </div>
    <div class="col-12">
        <div
          class="form-text d-none text-danger help"
          id="formNewSelectCompE${idOfNewComp}"
        >
          you must complete the information
        </div>
      </div>
  </div>
  `;
  // make the select searchable
  $(`#formNewSelectComp${idOfNewComp}`).selectize({
    sortField: "text",
  });
}

var myModal = new bootstrap.Modal(document.getElementById("addModal"), {
  keyboard: true,
});

// add new element to the page
function addNew() {
  // get the main information
  let name = document.getElementById("formNewName");
  let desc = document.getElementById("formNewDesc");
  let pic = document.getElementById("formNewPic");
  let flag = false;
  if (!name.value) {
    document.getElementById("formNewNameHelp").classList.remove("d-none");
    flag = true;
  } else document.getElementById("formNewNameHelp").classList.add("d-none");
  if (!desc.value) {
    document.getElementById("formNewDescHelp").classList.remove("d-none");
    flag = true;
  } else document.getElementById("formNewDescHelp").classList.add("d-none");
  if (!pic.value) {
    document.getElementById("formNewPicHelp").classList.remove("d-none");
    flag = true;
  } else document.getElementById("formNewPicHelp").classList.add("d-none");

  if (idOfNewComp <= 0) {
    Swal.fire("Error", "You need to add components.", "info");
    return;
  }

  let comp = {};
  let comp2 = {};
  let compK = [];
  let compK2 = [];
  // get the companiation
  for (var i = 1; i <= idOfNewComp; i++) {
    let k = document.getElementById("formNewSelectComp" + i).value;
    let k2 = document.getElementById("formNewSelectComp" + i).innerText;
    let v = document.getElementById("formNewSelectCompQ" + i).value;
    if (!k || !v || k == "Select Component") {
      document
        .getElementById("formNewSelectCompE" + i)
        .classList.remove("d-none");
      flag = true;
    } else
      document.getElementById("formNewSelectCompE" + i).classList.add("d-none");

    compK.push(k);
    compK2.push(k2);
    comp[k] = v;
    comp2[k2] = v;
  }

  if (flag) return;
  //load it to page
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
    `./php/adminMedInsert.php?name=${name.value}&desc=${desc.value}&pic=${
      pic.value
    }&qty=0&comp=${JSON.stringify(comp)}&compk=${JSON.stringify({
      k: compK.join(","),
    })}`,
    false
  );
  xmlhttp.send(null);
  console.log(result);
  if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
    result = xmlhttp.responseText;
  }

  // load to page
  if (result != "0") {
    add(1, name.value, desc.value, pic.value, 0, comp2, compK2);
    Swal.fire("Done!", "New Medicne added", "success");
    myModal.toggle();
  } else {
    Swal.fire("Error!", "Something went wrong" + result, "error");
    myModal.toggle();
  }
}

// open the modal, reset the information
function openModal() {
  myModal.toggle();
  document.getElementById("newFormCom").innerHTML = "";
  idOfNewComp = 0;
  document.getElementById("formNewName").value = "";
  document.getElementById("formNewDesc").value = "";
  document.getElementById("formNewPic").value = "";
  document.getElementById("formNewNameHelp").classList.add("d-none");
  document.getElementById("formNewDescHelp").classList.add("d-none");
  document.getElementById("formNewPicHelp").classList.add("d-none");
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

      xmlhttp.open("GET", `./php/adminMedDelete.php?id=${id}`, false);
      xmlhttp.send(null);
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        result = JSON.parse(xmlhttp.responseText);
      }

      // load to page
      if (result == 1) {
        document.getElementById("MedicneElement" + id).remove();
        Swal.fire(
          "Deleted!",
          "You deleted the Medicne " + name + ", ID: " + id,
          "success"
        );
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

window.addEventListener("load", start, false);
