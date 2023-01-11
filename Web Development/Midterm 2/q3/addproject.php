<?php


//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "submit"){

    /* Data info */
    $project_no = cleanData($_POST["project_no"]);
    $desc = cleanData($_POST["desc"]);
    $manager_no = cleanData($_POST["manager_no"]);
    $type = cleanData($_POST["type"]);
    $sd = cleanData($_POST["sd"]);
    $ed = cleanData($_POST["ed"]);

    //Calls the function to add the book to database
    addproject($project_no, $desc, $manager_no, $type, $sd, $ed);
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

function addproject($project, $desc, $manager, $type, $sd, $ed){

    $PageTitle = "Add a project";

    //Page header
    print<<<HERE

    <html>
        <body>

    HERE;

    include("myDB.php");
    include("PageFrame.php");

    $query = "SELECT * FROM project WHERE `project#`='$project'";
    $row1 = mysqli_num_rows(mysqli_query($myDB, $query));

    $query = "SELECT * FROM manager WHERE `project#`='$project'";
    $row2 = mysqli_num_rows(mysqli_query($myDB, $query));

    if ($row1 > 0 || $row1 != $row2){

        print "<h1>manager does not exist or already added..</h1>";
    }

    else{

        $query = "INSERT INTO project (`project#`, `description`, `manager#`, `type`, `Sdate`, `Edate`) VALUES ('$project', '$desc', '$manager', '$type', '$sd', '$ed')";
        mysqli_query($myDB, $query);

        print<<<HERE

        <h1>New project Has Been Added!</h1>
        <table class="brdr">
            <tr class="brdr">
            <th class="brdr">project no</th>
            <th class="brdr">description</th>
            <th class="brdr">manager no</th>
            <th class="brdr">type</th>
            <th class="brdr">start date</th>
            <th class="brdr">end date</th>
            </tr>
            <tr class="brdr">
                <td class="brdr">$project</td>
                <td class="brdr">$desc</td>
                <td class="brdr">$manager</td>
                <td class="brdr">$type</td>
                <td class="brdr">$sd</td>
                <td class="brdr">$ed</td>
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