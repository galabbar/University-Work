<?php

include("PageFrame.php");

$query = "SELECT Employee_No, Role, Nationality FROM Employee";
$Result = mysqli_query($myDB, $query);

?>

<body>
    <h1> Employee Number, Role and Nationality from the Employee Table</h1>
    <table>
        <tr>
            <th>manager#</th>
            <th>experience</th>
            <th>Nationality</th>
        </tr>
        <?php
                while ($Rows = mysqli_fetch_assoc($Result)){

                    $manager = $Rows["manager#"];
                    $exp = $Rows["experience"];
                    $Nationality = $Rows["nationality"];

                    print<<<HERE

                    <tr>
                        <td>$manager</td>
                        <td>$exp</td>
                        <td>$Nationality</td>
                    </tr>

                    HERE;
                }
            ?>
    </table>
</body>

</html>