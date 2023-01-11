<!DOCTYPE html>
<html>
<?php include("PageFrame.php") ?>
<main>
    <form name="MaintenanceForm" method="post" action="AddMaintenance.php">
        <table>
            <tr>
                <td>Task Number:</td>
                <td><input type="text" name="Task_No"></td>
            </tr>
            <tr>
                <td>Description:</td>
                <td><input type="text" name="Desc"></td>
            </tr>
            <tr>
                <td>Employee Number:</td>
                <td><input type="text" name="Employee_No"></td>
            </tr>
            <tr>
                <td>Status:</td>
                <td><input type="text" name="Status"></td>
            </tr>
            <tr>
                <td>Date:</td>
                <td><input type="date" name="Date"></td>
            </tr>
        </table>
        <input class="btn" type="submit" name="submit" value="submit">
    </form>
</main>

</html>