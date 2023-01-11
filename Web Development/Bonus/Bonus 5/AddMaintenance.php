<?php

if (isset($_POST['submit']) && $_POST['submit'] == "submit") {

    $Task_No = cleanData($_POST["Task_No"]);
    $Desc = cleanData($_POST["Desc"]);
    $Employee_No = cleanData($_POST["Employee_No"]);
    $Status = cleanData($_POST["Status"]);
    $Date = cleanData($_POST["Date"]);

    Add_Maintenance($Task_No, $Desc, $Employee_No, $Status, $Date);
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

function Add_Maintenance($Task_No, $Desc, $Employee_No, $Status, $Date)
{

    include("myDataBase.php");

    $query = "SELECT * FROM Maintenance WHERE Task_No='$Task_No' LIMIT 1";

    $Rows = mysqli_num_rows(mysqli_query($myDB, $query));

    include("PageFrame.php");

    if ($Rows > 0) {

        print "<h1>This Maintenance Row already exists in the database!</h1>";
    } else {

        $query = "INSERT INTO `Maintenance` (`Task_No`, `Description`, `Employee_No`, `Status`, `Date`) VALUES ('$Task_No', '$Desc', '$Employee_No', '$Status', '$Date')";
        mysqli_query($myDB, $query);

        print<<<HERE
            <h1>New Maintenance Row Added</h1>
            <table>
                <tr>
                    <th>Task Number</th>
                    <th>Description</th>
                    <th>Employee Number</th>
                    <th>Status</th>
                    <th>Date</th>
                </tr>
                <tr>
                    <td>$Task_No</td>
                    <td>$Desc</td>
                    <td>$Employee_No</td>
                    <td>$Status</td>
                    <td>$Date</td>
                </tr>
            </table>
        HERE;
    }
}

?>