<?php

include("PageFrame.php");
include("myDataBase.php");

$query = "SELECT
manager.name,
manager.nationality,
project.type,
project.description,
project.Sdate,
project.Edate
FROM
manager
INNER JOIN project ON `manager.manager#`=`project.manager#`
WHERE
project.Sdate > '1-1-2023'
AND project.Edate < '12-31-2028'";

$Result = mysqli_query($myDB, $query);
?>

<table>
    <tr>
        <th>name</th>
        <th>Nationality</th>
        <th>Description</th>
        <th>type</th>
        <th>start date</th>
        <th>end date</th>
    </tr>
    <?php
                while ($Rows = mysqli_fetch_assoc($Result)){

                    $Name = $Rows["name"];
                    $Nationality = $Rows["nationality"];
                    $Desc = $Rows["Description"];
                    $type = $Rows["type"];
                    $sd = $Rows["Sdate"];
                    $ed = $Rows["Edate"];

                    print<<<HERE

                    <tr>
                        <td>$Name</td>
                        <td>$Nationality</td>
                        <td>$Desc</td>
                        <td>$type</td>
                        <td>$sd</td>
                        <td>$ed</td>
                    </tr>

                    HERE;
                }
            ?>
</table>
</body>

</html>