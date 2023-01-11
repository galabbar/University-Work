<?php


$PageTitle = "Add manager";

include("PageFrame.php");

?>

<html>

<body>
    <!-- Form to add a new book -->
    <form method="post" action="addmanager.php">
        <h1>Add a new manager</h1>
        <table>
            <tr>
                <td>manager no</td>
                <td><input type="text" name="manager_no"></td>
            </tr>
            <tr>
                <td>name</td>
                <td><input type="text" name="name"></td>
            </tr>
            <tr>
                <td>experience</td>
                <td><input type="text" name="exp"></td>
            </tr>
            <tr>
                <td>nationality</td>
                <td><input type="text" name="nat"></td>
            </tr>
            <tr>
                <td>phone number</td>
                <td><input type="text" name="pn"></td>
            </tr>
            <tr>
                <td><input type="submit" name="submit" value="submit"></td>
            </tr>
        </table>
    </form>
</body>

</html>