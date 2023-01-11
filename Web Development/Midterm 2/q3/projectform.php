<?php


$PageTitle = "Add manager";

include("PageFrame.php");

?>

<html>

<body>
    <!-- Form to add a new book -->
    <form method="post" action="AddBook.php">
        <h1>Add a new manager</h1>
        <table>
            <tr>
                <td>project no</td>
                <td><input type="text" name="project_no"></td>
            </tr>
            <tr>
                <td>description</td>
                <td><input type="text" name="desc"></td>
            </tr>
            <tr>
                <td>manager_no</td>
                <td><input type="text" name="manager_no"></td>
            </tr>
            <tr>
                <td>type</td>
                <td><input type="text" name="type"></td>
            </tr>
            <tr>
                <td>start date</td>
                <td><input type="text" name="sd"></td>
            </tr>
            <tr>
                <td>end date</td>
                <td><input type="text" name="ed"></td>
            </tr>
            <tr>
                <td><input type="submit" name="submit" value="submit"></td>
            </tr>
        </table>
    </form>
</body>

</html>