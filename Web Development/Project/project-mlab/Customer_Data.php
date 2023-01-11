<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Customer_Data.html
Project Phase: 2
-->

<!DOCTYPE html>
<!-- 
    Template Page
 -->
<html lang="en">
  <head>
    <!-- Meta tages -->
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <!-- view port -->
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <!-- website information -->
    <meta
      name="description"
      content="A website that helps Lab Manager to manage it"
    />
    <meta name="keywords" content="Lab, Chem, Pharmacy" />
    <meta name="author" content="Hassan Khalaf, Rania Kharnoub, Ghazi AlAbar" />

    <!-- CSS -->
    <link href="./css/bootstrap.css" rel="stylesheet" crossorigin="anonymous" />
    <link rel="stylesheet" href="./css/style.css" />

    <link rel="shortcut icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <link rel="icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <title>Mlab &rarr; Invoice</title>
  </head>
  <body id="template" class="bg-white">
    <div class="container-fluid bg-white py-3 mt-5">
      <div class="mt-4"></div>
      <div class="row">
        <div class="col-md-6 mx-auto">
          <div class="card card-body">
            <h3 class="text-center mb-4">Customer Data</h3>
            <hr />
            <!-- method="post" action -->
            <form
              class="form-group mt-5"
              method="post"
              action="Result_Page.php"
            >
              <div class="mb-3">
                <label>Name:</label>
                <input
                  class="form-control input-lg"
                  placeholder="Customer's Name"
                  name="name"
                  type="text"
                />
              </div>
              <div class="mb-3">
                <label>Email</label>
                <input
                  class="form-control input-lg"
                  placeholder="Customer's Email"
                  name="email"
                  type="text"
                />
              </div>
              <div class="mb-3">
                <label>Civil ID:</label>
                <input
                  class="form-control input-lg"
                  placeholder="Civil ID"
                  name="cid"
                  type="text"
                />
              </div>
              <div class="mb-3">
                <label>Phone Number: </label>
                <input
                  class="form-control input-lg"
                  placeholder="Customer's Phone Number"
                  name="phone_number"
                  type="text"
                />
              </div>
              <div class="mb-3">
                <label>Date:</label>
                <input class="form-control input-lg" name="date" type="date" />
              </div>
              <div class="mt-5">
                <a href="Pharmacist_Cart_Page.php">
                  <button type="button" class="btn btn-primary">Cancel</button>
                </a>
                <input
                  type="submit"
                  value="submit"
                  name="submit"
                  class="btn btn-primary"
                />
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>

    <!-- geneal Java Script -->
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"
    ></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <!-- local  -->
    <script src="./js/template.js"></script>
  </body>
</html>

<!-- 
A "Results" page should be made with php. it prints on the document if the payment is succesful or not. If not, show why
There should be a "print
invoice" button and also there should be a "go back to the main page" button
that also deletes all the cookies
-->
