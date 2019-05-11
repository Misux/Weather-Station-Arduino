<?php 
$host="localhost"; 
$username="root";
$password="supp";
$nome_db="Stazione_Meteo";

$db = mysql_connect($host, $username, $password) or die ("Il DataBase non &egrave momentaneamente disponibile"); //mysql -u root -p

// si connette al server mysql del database fornendo i dati
$db1 = mysql_select_db($nome_db, $db) or die (mysql_error());
// seleziona o scegli il tuo database
?>
