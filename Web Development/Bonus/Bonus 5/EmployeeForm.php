<!DOCTYPE html>
<html>
<?php include("PageFrame.php") ?>
<main>
    <form name="EmployeeForm" method="post" action="AddEmployee.php">
        <table>
            <tr>
                <td>Employee Number:</td>
                <td><input type="text" name="Employee_No"></td>
            </tr>
            <tr>
                <td>Name:</td>
                <td><input type="text" name="Name"></td>
            </tr>
            <tr>
                <td>Role:</td>
                <td><input type="text" name="Role"></td>
            </tr>
            <tr>
                <td>Nationality:</td>
                <td><input type="text" name="Nationality"></td>
            </tr>
            <tr>
                <td>Phone Number:</td>
                <td><input type="text" name="PN"></td>
            </tr>
        </table>
        <input class="btn" type="submit" name="submit" value="submit">
    </form>
</main>

</html>