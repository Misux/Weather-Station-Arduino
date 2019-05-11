<html>
<style>
body{
	background-image:url('Skyblu.jpg');
	color:white;
}</style>
<body>
	<p align="center">
	<font face="verdana" size="15" color="white"> Dati Rilevati </font><br><br>
	<title> Stazione Meteo </title>
	
	<?php

	

	include ("controllo_sessione.php");
	include("dbconnect.php");

	
	$query = "SELECT * FROM rilevazioni;";
	$output = mysql_query($query);
	if(mysql_num_rows($output) == 0){
		echo "Nessun elemento nel database.";
	}else{
		while($row=mysql_fetch_object($output)){
			echo $row->Cap_zona;
			echo "<br>";
			echo $row->giorno;
			echo "<br>";
			echo $row->ora;
			echo "<br>";
			echo $row->temperatura;
			echo "<br>";
			echo $row->umidita;
			echo "<br>";
			echo $row->pressione;
			echo "<br>";
			echo $row->distanza;
			echo "<br>";
			echo $row->inquinamento;
			echo "<br>";
		}	
	}
	?>
<p align="center"><INPUT TYPE="button" VALUE="Esci" onClick="window.location.href='logout.php'"> </FORM></p>

</body>
</html>
