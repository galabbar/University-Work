<?php
   

if (isset($_POST['submit']) && $_POST['submit'] == "submit") {
    

    $Employee_No = cleanData($_POST["Employee_No"]);
    $Name = cleanData($_POST["Name"]);
    $Role = cleanData($_POST["Role"]);
    $Nationality = cleanData($_POST["Nationality"]);
    $PN = cleanData($_POST["PN"]); //Phone Number

    Add_Employee($Employee_No, $Name, $Role, $Nationality, $PN);
}

function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);
    return $data;
}

function Add_Employee($Employee_No, $Name, $Role, $Nationality, $PN)
{

    include("myDataBase.php");

    include("PageFrame.php");

    $query = "SELECT * FROM Employee WHERE Employee_No='$Employee_No' LIMIT 1";

    $Rows = mysqli_num_rows(mysqli_query($myDB, $query)); //Counts how many rows have the same Employee id

    

    if ($Rows > 0) {
        print "<h1>The Employee already exists in the database!</h1>";
    } else {

        $query = "INSERT INTO `Employee` (`Employee_No`, `Name`, `Role`, `Nationality`, `Phone_Number`) VALUES ('$Employee_No', '$Name', '$Role', '$Nationality', '$PN')";

        mysqli_query($myDB, $query);

        print<<<HERE
            
            <h1>New Employee Added</h1>
            <table>
                <tr>
                    <th>Employee Number</th>
                    <th>Name</th>
                    <th>Role</th>
                    <th>Nationality</th>
                    <th>Phone Number</th>
                </tr>
                <tr>
                    <td>$Employee_No</td>
                    <td>$Name</td>
                    <td>$Role</td>
                    <td>$Nationality</td>
                    <td>$PN</td>
                </tr>
            </table>
        HERE;
    }
}

?>