<?php
include("dbconnect.php");
?>

<html>
<head>

<style>
{
  color:white;
  background-repeat:no-repeat;
}
</style>

		<SCRIPT>
			function Verifica()
			{
			if ((form.user.value !="") && (form.pass.value !=""))
			{
			header("location:loggato.php");
			return true;
			}
			else
			{
			alert("Hey furbacchione!!! Devi inserire login e password");
			return false;
			exit;
			}
			}
		</SCRIPT>
</head>
<center><body link="white" alink="yellow" vlink="white" background="./images22.jpg" alignment="center"></center>


<form  name=form method=POST action=log.php onSubmit="return Verifica()"> 
<p align="center" >   

<title> Login </title>
<br><br> 
   
<span  class="Stile5">Username</span><br>            
            <input name=user type=username class="Stile1" size=15>
<br><br>
<span  class="Stile5">Password</span><br>
            <input name=pass type=password class="Stile1" size=15> 
        
         <br><br><br>

<input name="submit" type=submit class="Stile1" value=Accedi> 
<br><br><br>
<a href="registrazione.php"> Registrati Ora </a></p> 
</form>


</body>
</html>

