<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

 $fname = test_input($_POST["fname"]);
if (!preg_match("/^[a-zA-Z ]*$/",$fname)) {
  $fnameErr = "Only letters and white space allowed";
}
  $lname = test_input($_POST["lname"]);
if (!preg_match("/^[a-zA-Z ]*$/",$lname)) {
  $lnameErr = "Only letters and white space allowed";
}
 $email = test_input($_POST["email"]);
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
  $emailErr = "Invalid email format";
}

if(empty($Mobnumber)) {
$msg = "Please enter a value";
} else if(!is_numeric($Mobnumber)) {
$msg = "Data entered was not numeric";
} else if(strlen($Mobnumber) != 10) {
$msg = "The number entered was not 10 digits long";
}else{
 $Mobnumber = test_input($Mobnumber);
}
 
if(empty($zip)) {
$msg = "Please enter a value";
} else if(!is_numeric($zip)) {
$msg = "Data entered was not numeric";
} else if(strlen($zipr) != 6) {
$msg = "The number entered was not 6 digits long";
}else{
 $zip = test_input($zip);
}

 if (empty($_POST["gender"])) {
    $genderErr = "Gender is required";
  } else {
    $gender = test_input($_POST["gender"]);
  }

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

}
?>
