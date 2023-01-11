<?php

include("PageFrame.php");
include("myDataBase.php");

$query = "SELECT Employee_No, Role, Nationality FROM Employee";
$Result = mysqli_query($myDB, $query);
?>

<html>

<body>
    <h1> Employee Number, Role and Nationality from the Employee Table</h1>
    <table>
        <tr>
            <th>Employee Number</th>
            <th>Role</th>
            <th>Nationality</th>
        </tr>
        <?php
                while ($Rows = mysqli_fetch_assoc($Result)){

                    $Employee_No = $Rows["Employee_No"];
                    $Role = $Rows["Role"];
                    $Nationality = $Rows["Nationality"];

                    print<<<HERE

                    <tr>
                        <td>$Employee_No</td>
                        <td>$Role</td>
                        <td>$Nationality</td>
                    </tr>

                    HERE;
                }
            ?>
    </table>
</body>

</html>