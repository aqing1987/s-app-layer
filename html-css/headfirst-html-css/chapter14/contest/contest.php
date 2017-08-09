<?php
if ($_POST) {
    $firstname = $_POST["firstname"];
    $lastname = $_POST["lastname"];
?>

<!DOCTYPE html>
<html>
  <head>
    <meta name="robots" content="noindex,  nofollow">
    <meta charset="utf-8">
    <title>Chapter 14 Contest</title>
  </head>
  <body>
    <p>
      firstname: <?php print($firstname) ?>
      <br/>
      lastname: <?php print($lastname) ?>
    </p>
  </body>
</html>

<?php
}
?>
