<?php
include ("dbconnect.php");
include ("controllo_sessione.php");
?>
<html>
<head>
<style>
{
  
  background-repeat:no-repeat;
}
</style>
</head>

<body  link="white" alink="yellow" vlink="white" background="./images22.jpg"> 
	<title> Temperature </title>
	<p align="center">
	<font face="verdana" size="15" color="ffffff">Home</font><br><br>
	<a href="visualizza.php"> Temperature </a><br>
	<a href="Umidita.php"> Luce </a><br>
	<a href="Rumuro.php"> Umidita </a><br>
	<a href="luce.php"> Rumore </a> </p>
	<br>
	<p align="center"><INPUT TYPE="button" VALUE="Esci" onClick="window.location.href='logout.php'"> </FORM></p>

</body>
</html> 
