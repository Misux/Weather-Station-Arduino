<?php 
$host="localhost"; 
$username="Ospite";
$password="supp";
$nome_db="Rilevazioni";

$db = mysql_connect($host, $username, $password) or die ("Il DataBase non è momentaneamente disponibile"); //mysql -u ospite -p

// si connette al server mysql del database fornendo i dati
mysql_select_db($nome_db, $db) or die ("Il DataBase non è momentaneamente disponibile");
// seleziona o scegli il tuo database
?>
