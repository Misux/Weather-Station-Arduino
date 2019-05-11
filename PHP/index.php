<html>
<head>
<title> Login </title>
<style>
{
  color:white;
  background-repeat:no-repeat;
}
body{
	background-image:url('sky-home.jpg');
	color:white;
	
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

<center><body link="white" alink="yellow" vlink="white" background="./skyblu.jpg" alignment="center"></center>
<p align="center"><font face="verdana" size="15" color="white"> Stazione Meteo </font></p><br>
<form  name=form method=POST action=log.php onSubmit="return Verifica()"> 
<p align="center" >   


<br><br> 
   
Username:<br>            
            <input name=user type=username size=15>
<br><br>
Password:<br>
            <input name=pass type=password size=15> 
        
         <br><br><br>

<input name="submit" type=submit value=Accedi>&nbsp&nbsp&nbsp&nbsp<input name="submit" type=reset value=Annulla>
<br><br><br>
<a href="registrazione.php"> Registrati Ora </a></p> 
</form>


</body>
</html>

