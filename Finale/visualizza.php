<html>
<body style="background-color: rgb(0, 151, 155)">
	<p align="center">
	<font face="verdana" size="15" color="white"> Rilevazioni </font><br><br>
	<title> Rilevazioni </title>
	
	<?php

	

	include ("controllo_sessione.php");
	include("dbconnect.php");

	
	$query = "SELECT * FROM rilevazioni;";
	$output = mysql_query($query);
	if(mysql_num_rows($output) == 0){
		echo "Nessun elemento nel database.";
	}else{
		while($row=mysql_fetch_object($output)){
			echo $row->cod_sede;
			echo "<br>";
			echo $row->giorno;
			echo "<br>";
			echo $row->ora;
			echo "<br>";
			echo $row->temperatura;
			echo "<br>";
			echo $row->luce;
			echo "<br>";
			echo $row->umidita;
			echo "<br>";
			echo "<br>";
			echo "<br>";
		}	
	}
	?>
<p align="center"><INPUT TYPE="button" VALUE="Esci" onClick="window.location.href='logout.php'"> </FORM></p>

</body>
</html>
