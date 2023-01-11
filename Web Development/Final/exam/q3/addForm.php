<!DOCTYPE html>
<html>

<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>add table</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>

<body>
    <?php
    include "header.php";
    ?>
    <form method="post" action="addTable.php">
        <p>
            <label>col1:</label>
            <input type="text" name="id">
        </p>
        <p>
            <label>col2:</label>
            <input type="text" name="name">
        </p>
        <p>
            <label>col1:</label>
            <input type="text" name="hosp">
        </p>
        <p>
            <label>col1:</label>
            <input type="text" name="date">
        </p>
        <input type="submit" name="submit">
    </form>
</body>

</html>