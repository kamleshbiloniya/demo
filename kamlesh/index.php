 <!DOCTYPE html>
<html>
<head>
<link href="style.css" rel="stylesheet" type="text/css">
 <script src="myscript.js"></script>
<a href="uploads">link</a>
</head>
<body>
<h2>Student Registration form </h2>
<form method="post" name="myform" action="" onsubmit="return validationForm()" >
  <fieldset >

Full name:<input type="text" name="name" maxlength="20" id="myInput1">
<span class="error" id="nameid">*</span>
<br><br>
<p>Address:</p><textarea name="address" rows="4" cols="50" maxlength="10" id="myInput"></textarea>
<span class="error" id="addid">*</span>
<br><br>
E-mail: <input type="text" name="email" id="myInput" >
<span class="error" id="emailid">* <?php echo $emailErr;?></span><br><br>
Rollno:<input type="number" name="rollno" maxlength="6" id="myInput" >
<span class="error" id="rollnoid">* <?php echo $mobileErr;?></span><br><br>
Year:<input type="number" name="year" id="myInput" >
<span class="error" id="yearid">* <?php echo $acnumberErr;?></span><br><br>
Password: <input type="password" name="passwd" id="myInput6" >
<span class="error" id="passwdid">* <?php echo $passwdErr;?></span><br><br>
<input type="checkbox" onclick="myFunction()">Show Password<br><br>
<input type="submit" name="submit" value="submit">
<input type="reset" value="Clear">
</fieldset >

</form>
</body>
</html>


