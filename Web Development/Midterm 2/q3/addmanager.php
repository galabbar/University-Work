<?php



//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "submit"){

    /* Data info */
    $manager_no = cleanData($_POST["manager_no"]);
    $name = cleanData($_POST["name"]);
    $exp = cleanData($_POST["exp"]);
    $nat = cleanData($_POST["nat"]);
    $pn = cleanData($_POST["pn"]);

    
    addmanager($manager_no, $name, $exp, $nat, $pn);
}

//cleans values from the user input
function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);

    return $data;
}


function addmanager($manager, $name, $exp, $nat, $pn){

    $PageTitle = "Add a Book";

    //Page header
    print<<<HERE

    <html>
        <body>

    HERE;

    include("myDB.php");
    include("PageFrame.php");

    $query = "SELECT * FROM manager WHERE `manager#`='$manager'";
    $Rows = mysqli_num_rows(mysqli_query($myDB, $query));

    if ($Rows > 0){

        print "<h1>The Book Already Exists..</h1>";
    }

    else{

        $query = "INSERT INTO manager (`managr#`, `name`, `experience`, `nationality`, `phone#`) VALUES('$manager', '$name', '$exp', '$nat', '$pn')";
        mysqli_query($myDB, $query);

        print<<<HERE
        <h1>New manager Has Been Added!</h1>
        <table class="brdr">
            <tr class="brdr">
            <th class="brdr">ID</th>
                <th class="brdr">manager no</th>
                <th class="brdr">name</th>
                <th class="brdr">experience</th>
                <th class="brdr">nationality</th>
                <th class="brdr">phone number</th>
            </tr>
            <tr class="brdr">
                <td class="brdr">$manager</td>
                <td class="brdr">$name</td>
                <td class="brdr">$exp</td>
                <td class="brdr">$nat</td>
                <td class="brdr">$pn</td>
            </tr>
        </table>
        HERE;

    }

    print<<<HERE

    </body>
        </html>

    HERE;
    
}
?>