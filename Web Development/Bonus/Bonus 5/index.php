<?php

include("PageFrame.php");
include("myDataBase.php");

print<<<HERE
    <span class="Center-Span">
        <span>
            <h1>Employee Table</h1>
            <table>
                <tr>
                    <th>Employee Number</th>
                    <th>Name</th>
                    <th>Role</th>
                    <th>Nationality</th>
                    <th>Phone Number</th>
                </tr>

HERE;

$query = "SELECT * FROM Employee ORDER BY Employee_No ASC";
$Result = mysqli_query($myDB, $query);

while($Row = mysqli_fetch_assoc($Result)){

    $Employee_No = $Row["Employee_No"];
    $Name = $Row["Name"];
    $Role = $Row["Role"];
    $Nationality = $Row["Nationality"];
    $PN = $Row["Phone_Number"];

    print<<<HERE
        <tr>
            <td>$Employee_No</td>
            <td>$Name</td>
            <td>$Role</td>
            <td>$Nationality</td>
            <td>$PN</td>
        </tr>
    HERE;
}

print "</table></span>";

$query = "SELECT * FROM Maintenance ORDER BY Task_No ASC";
$Result = mysqli_query($myDB, $query);

print<<<HERE
    <span>
        <h1>Maintenance Table</h1>
        <table>
            <tr>
                <th>Task Number</th>
                <th>Description</th>
                <th>Employee Number</th>
                <th>Status</th>
                <th>Date</th>
            </tr>
HERE;

while ($Row = mysqli_fetch_assoc($Result)){

    $Task_No = $Row["Task_No"];
    $Desc = $Row["Description"];
    $Employee_No = $Row["Employee_No"];
    $Status = $Row["Status"];
    $Dates = $Row["Date"];

    print<<<HERE
        <tr>
            <td>$Task_No</td>
            <td>$Desc</td>
            <td>$Employee_No</td>
            <td>$Status</td>
            <td>$Dates</td>
        </tr>
    HERE;
}

print "</table></span></span>";

?>