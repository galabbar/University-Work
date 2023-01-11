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



function start() {
  //nav tool tips enabling
  var tooltipTriggerList = [].slice.call(
    document.querySelectorAll('[data-bs-toggle="tooltip"]')
  );
  tooltipTriggerList.map(function (tooltipTriggerEl) {
    return new bootstrap.Tooltip(tooltipTriggerEl);
  });


  // load from data base the data and set them
  // these infromation are fixed for testing
  let countUsersCharts = 1;
  let nameUsers = "User Logs";
  let adminUser= 3;
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
            label: "Dataset 1",
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
  

  
  
  // load items to page
  for (var i = 1; i <= countUsersCharts; i++) {
    drawUsersChart (i, nameUsers, pharmacistUser,ChemistUser,adminUser);
  }
}

// Admin
function AdminList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  // fixed list of Admins
  for (var i = 1; i <= 3; i++) {
 
 
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                <tr>
               
                    <td>Name:AdminUser</td>
                    <br>
                    <td>Type:Admin</td>
                    <br>
                    <td>Action:Add new User</td>
                    <br>
                    <td>15/11/2022</td>
                    
              </tr>
                
            </div>
            `;

  // add it to the page
  
  container2.append(newElement);
  
 
}
}



// Pharmacist
function PharmacistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  for (var i = 1; i <= 2; i++) {
 
 
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div class="card bg-white p-0 shadow overflow-hidden"  ">
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                <tr>
               
                    <td>Name:PharmacistUser</td>
                    <br>
                    <td>Type:Pharmacist</td>
                    <br>
                    <td>Action:sell items</td>
                    <br>
                    <td>19/11/2022</td>
                    
              </tr>
                
            </div>
            `;

  // add it to the page
  container2.append(newElement);
}
}


// Chemist
function ChemistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  for (var i = 1; i <= 2; i++) {
 
 
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
            <!-- item -->
              <div class="card bg-white p-0 shadow overflow-hidden"  ">
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                <tr>
               
                    <td>Name:ChemistUser</td>
                    <br>
                    <td>Type:Chemist</td>
                    <br>
                    <td>Action:make a combination</td>
                    <br>
                    <td>15/11/2022</td>
                    
              </tr>
                
            </div>
            `;

  // add it to the page
  container2.append(newElement);
}
}
function sortTable(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("logsTable");
  switching = true;
  //Set the sorting direction to ascending:
  dir = "asc"; 
  /*Make a loop that will continue until
  no switching has been done:*/
  while (switching) {
    //start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /*Loop through all table rows (except the
    first, which contains table headers):*/
    for (i = 1; i < (rows.length - 1); i++) {
      //start by saying there should be no switching:
      shouldSwitch = false;
      /*Get the two elements you want to compare,
      one from current row and one from the next:*/
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      /*check if the two rows should switch place,
      based on the direction, asc or desc:*/
      if (dir == "asc") {
        if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
          //if so, mark as a switch and break the loop:
          shouldSwitch= true;
          break;
        }
      } else if (dir == "desc") {
        if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
          //if so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      /*If a switch has been marked, make the switch
      and mark that a switch has been done:*/
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      //Each time a switch is done, increase this count by 1:
      switchcount ++;      
    } else {
      /*If no switching has been done AND the direction is "asc",
      set the direction to "desc" and run the while loop again.*/
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}





// on load page
window.addEventListener("load", start, false);
