<?php
	$conn=mysql_connect("localhost", "root", "supp");
	if(! $conn) {
		exit("errore connessione a mysql");
	}else{
		echo "connessione a mysql riuscita. <br><hr>";
	}

$var_Cap_zona=$_GET["Cap_zona"];
$var_temp=$_GET["temperatura"];
$var_um=$_GET["umidita"];
$var_pressione=$_GET["pressione"];
$var_distanza=$_GET["distanza"];
$var_inquinamento=$_GET["inquinamento"];


$ora=time();
$data=date('H:i:s - Y M d ', $ora);
echo "$data  <br> <hr>";



mysql_select_db("Stazione_Meteo") or exit("errore con db temperatura");

$sqlcmd ="insert into rilevazioni (Cap_zona, giorno, ora, temperatura, umidita, pressione, distanza, inquinamento) values ('$var_Cap_zona',CURDATE(),CURTIME(),'$var_temp','$var_um','$var_pressione', )'$var_distanza', '$var_inquinamento',  ";
$inserimento_temperatura=mysql_query($sqlcmd) or die (mysql_error());


mysql_close($conn);
?>
