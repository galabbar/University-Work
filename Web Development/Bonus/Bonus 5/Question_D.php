<?php

include("PageFrame.php");
include("myDataBase.php");

$query = "SELECT
Employee.Name,
Employee.Employee_No,
Employee.Nationality,
Employee.Role,
Maintenance.Description,
Maintenance.Status,
Maintenance.Date
FROM
Employee
INNER JOIN Maintenance ON Employee.Employee_No = Maintenance.Employee_No
WHERE
Maintenance.Date < NOW()
AND Employee.Role IN ('Supervisor')";

$Result = mysqli_query($myDB, $query);
?>

<html>

<body>
    <h1>Information about employees with their name, Nationality, Task Description, Status, Date before today's date
        (11/20/2022), and Supervisor Role</h1>
    <table>
        <tr>
            <th>Employee Name</th>
            <th>Nationality</th>
            <th>Description</th>
            <th>Status</th>
            <th>Date</th>
            <th>Role</th>
        </tr>
        <?php
                while ($Rows = mysqli_fetch_assoc($Result)){

                    $Name = $Rows["Name"];
                    $Nationality = $Rows["Nationality"];
                    $Desc = $Rows["Description"];
                    $Status = $Rows["Status"];
                    $Date = $Rows["Date"];
                    $Role = $Rows["Role"];

                    print<<<HERE

                    <tr>
                        <td>$Name</td>
                        <td>$Nationality</td>
                        <td>$Desc</td>
                        <td>$Status</td>
                        <td>$Date</td>
                        <td>$Role</td>
                    </tr>

                    HERE;
                }
            ?>
    </table>
</body>

</html>