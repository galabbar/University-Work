<?php


$PageTitle = "Home Page";
include("PageFrame.php");
include("myDB.php");

$query = "SELECT * FROM manager"; 

$Result = mysqli_query($myDB, $query); //executes the query in the mysql server

print <<<HERE

<html>
<body>
<h1>manager table</h1>
<table class="brdr">
    <tr class="brdr">
        <th class="brdr">manager no</th>
        <th class="brdr">name</th>
        <th class="brdr">experience</th>
        <th class="brdr">nationality</th>
        <th class="brdr">phone number</th>
    </tr>

HERE;

while ($Row = mysqli_fetch_assoc($Result)){

    $manager = $Row["manager#"];
    $name = $Row["name"];
    $exp = $Row["experience"];
    $nat = $Row["nationality"];
    $pn = $Row["phone#"];

    print<<<HERE

    <tr class="brdr">
        <td class="brdr">$manager</td>
        <td class="brdr">$name</td>
        <td class="brdr">$exp</td>
        <td class="brdr">$nat</td>
        <td class="brdr">$pn</td>
    </tr>

    HERE;
}


print <<<HERE

</table>
<h1>project table</h1>
<table class="brdr">
    <tr class="brdr">
    <th class="brdr">project no</th>
    <th class="brdr">description</th>
    <th class="brdr">manager</th>
    <th class="brdr">type</th>
    <th class="brdr">start date</th>
    <th class="brdr">end date</th>
    </tr>

HERE;

$query = "SELECT * FROM project"; 

$Result = mysqli_query($myDB, $query);

while ($Row = mysqli_fetch_assoc($Result)){

    $project = $Row["project#"];
    $manager = $Row["manager#"];
    $desc = $Row["description"];
    $type = $Row["type"];
    $sd = $Row["Sdate"];
    $ed = $Row["Edate"];

    print<<<HERE

    <tr class="brdr">
        <td class="brdr">$project</td>
        <td class="brdr">$desc</td>
        <td class="brdr">$manager</td>
        <td class="brdr">$type</td>
        <td class="brdr">$sd</td>
        <td class="brdr">$ed</td>
    </tr>

    HERE;
}

print <<<HERE

        </table>
    </body>
</html>

HERE;

?>