/*
  Rania Kharnoub
  2201131226 
  Updated Phase 1
*/
// Charts Vars
let AllUsersChart = [];
let container = document.getElementById("usersChartDiv");
let container2 = document.getElementById("ListOfUsers");
let userImage = "./imgs/profile.png";
let countUsersPerType = 2;  // test fixed value


// load from data base the data and set them
  // these infromation are fixed for testing
  let countUsersCharts = 1;
  let nameUsers = "Users";
  let adminUser= 2;
  let pharmacistUser = 2;
  let ChemistUser= 2;
  

  // Load users Chart:
  function drawUsersChart (id, nameUsers, pharmacistUser,ChemistUser,adminUser) {
    // define the new element 
    let newElement = document.createElement("div");
    newElement.id = "usersChartElement" + id;
    newElement.classList = "col-md-3 mb-3";
    newElement.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" >
                    <canvas id="usersCanvas${id}"></canvas>
                    <div class="d-flex justify-content-between align-items-center mt-4" >
                      <button class="btn btn-sm btn-primary" onclick="AdminList(${id});">Admin</button>
                      <button class="btn btn-sm btn-primary" onclick="PharmacistList(${id});">Pharmacist</button>
                      <button class="btn btn-sm btn-primary" onclick="ChemistList(${id});">Chemist</button>
                    </div>
                  </div>
              `;
  
    // add it to the page
    container.append(newElement);
  
    // config the chart of it
    const config = {
      type: "doughnut",
      data: {
        labels: ["Admin", "pharmacist", "Chemist"],
        datasets: [
          {
            label: "",
            data: [parseInt(adminUser), parseInt(pharmacistUser),parseInt(ChemistUser)],
            backgroundColor: ["grey", "#f2545b", "#19323c"],
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
            text: nameUsers,
          },
        },
      },
    };
    // load the chart
    AllUsersChart.push(
      new Chart(document.getElementById("usersCanvas" + id), config)
    );
  }

  // Call
  




function start() {
  //nav tool tips enabling
  var tooltipTriggerList = [].slice.call(
    document.querySelectorAll('[data-bs-toggle="tooltip"]')
  );
  tooltipTriggerList.map(function (tooltipTriggerEl) {
    return new bootstrap.Tooltip(tooltipTriggerEl);
  });
 
  // load items to page
  for (var i = 1; i <= countUsersCharts; i++) {
    drawUsersChart (i, nameUsers, pharmacistUser,ChemistUser,adminUser);
  }
}

// Admin
function AdminList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  // fixed list of Admins
  for (var i = 1; i <= adminUser; i++) {
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div  id="adminUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="adminUserNameP${i}">AdminUser</p>
                    <p contenteditable="true" id="adminTypeP${i}">Admin</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="AdminMailP${i}"> <a href = "mailto: AdminUser@MLab.com">AdminUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'AdminType');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;

  // add it to the page
  container2.append(newElement);
 
}
}




// Pharmacist
function PharmacistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  // fixed list of Pharmacists
  for (var i = 1; i <= pharmacistUser; i++) {
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div  id="PharmacistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="PharmacistUserNameP${i}">PharmacistUser</p>
                    <p contenteditable="true" id="PharmacistTypeP${i}">Pharmacist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="PharmacistMailP${i}"> <a href = "mailto: PharmacistUser@MLab.com">PharmacistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'PharmacistType');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;

  // add it to the page
  container2.append(newElement);
 
}
}


// Chemist
function ChemistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  // fixed list of Chemists
  for (var i = 1; i <= ChemistUser; i++) {
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div  id="ChemistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="ChemistUserNameP${i}">ChemistUser</p>
                    <p contenteditable="true" id="ChemistTypeP${i}">Chemist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="ChemistMailP${i}"> <a href = "mailto: ChemistUser@MLab.com">ChemistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'ChemistType');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;

  // add it to the page
  container2.append(newElement);
 
}
}














function Edit(id) {

Swal.fire("", "You can modify by clicking on the user details directly", "");

}


function Delete(id,uType)

{
  
  //document.getElementById("ListOfUsers").innerHTML=""
  
  
  if (uType=="AdminType")
  {
    document.getElementById("adminUserDiv" + id).innerHTML=""
    adminUser--;
  }
  
  else if (uType=="PharmacistType")
  {
    document.getElementById("PharmacistUserDiv" + id).innerHTML=""
    pharmacistUser--;
  }
  else
  {
    document.getElementById("ChemistUserDiv" + id).innerHTML=""
    ChemistUser--;
  }
  //$("#usersChartDiv").load(window.location.href + " #usersChartDiv" );
  AllUsersChart[0].data.datasets[0].data = [parseInt(adminUser), parseInt(pharmacistUser),parseInt(ChemistUser)];
  AllUsersChart[0].update();
}


function Adduser(id)
{
  let NewUserName = document.getElementById("UserName").value;
  let NewUserEmail = document.getElementById("UserEmail").value;
  let NewUserType = document.getElementById("userType").value;
  if (NewUserType == "admin")
    {
       adminUser= adminUser+1;
       id=adminUser;
    }
    else if (NewUserType == "pharmacist")
    {
      pharmacistUser= pharmacistUser +1;
      id=pharmacistUser;
    }
    else
    {
      ChemistUser= ChemistUser+1;
      id=ChemistUser;
    }
    
    
    let newElement = document.createElement("div");
    let i=id;
    newElement.classList = "col-md-3 mb-3";
    if (NewUserType == "admin")
    {
      newElement.innerHTML = `
      <!-- item -->
      <div  id="adminUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
        <!-- img -->
        <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
        <!-- details -->
             <p contenteditable="true" id="adminUserNameP${i}">${NewUserName}</p>
            <p contenteditable="true" id="adminTypeP${i}">${NewUserType}</p>
            <!--mailto -> to make it email-->
            <p contenteditable="true" id="AdminMailP${i}"> <a href = "mailto:${NewUserName}">${NewUserEmail}</a></p>        
          <div class="d-flex justify-content-between align-items-center mt-4">
          <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'AdminType');">Delete</button>
          <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
          
        </div>
       
       
      </div>
                `;
    }
    else if (NewUserType == "pharmacist")
    {
      newElement.innerHTML = `
            <!-- item -->
              <div  id="PharmacistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="PharmacistUserNameP${i}">PharmacistUser</p>
                    <p contenteditable="true" id="PharmacistTypeP${i}">Pharmacist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="PharmacistMailP${i}"> <a href = "mailto: PharmacistUser@MLab.com">PharmacistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'PharmacistType');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;

      
    }
    else
    {
      newElement.innerHTML = `
            <!-- item -->
              <div  id="ChemistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="ChemistUserNameP${i}">ChemistUser</p>
                    <p contenteditable="true" id="ChemistTypeP${i}">Chemist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="ChemistMailP${i}"> <a href = "mailto: ChemistUser@MLab.com">ChemistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'ChemistType');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;
    }
    
  // add it to the page
  
  container2.append(newElement);
  AllUsersChart[0].data.datasets[0].data = [parseInt(adminUser), parseInt(pharmacistUser),parseInt(ChemistUser)];
  AllUsersChart[0].update();
  
}



// on load page
window.addEventListener("load", start, false);
