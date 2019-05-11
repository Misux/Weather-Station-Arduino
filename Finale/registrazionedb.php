<?php
include ("dbconnect.php");

?>

<html>

<body>

<?php
$user= $_POST['username'];



  

   $query = "SELECT * from utenti WHERE username = '$user'"; // selezioni da utenti 

   $risultato = mysql_query($query);

   $num_righe = mysql_num_rows($risultato); // controlla nel database se lo user e la password esistono almeno logga

   if($num_righe)

   {

 
   header("location: registrazione_esistente.php");
   
 } 


else
{

$stringa_query="insert into utenti (username,password,privilegi,codice_sede) values('" . $_POST  ['username'] . "','" . $_POST['password'] . "','0','" . $_POST['codice_sede'] . "')";
$iscrizione_utente=mysql_query($stringa_query) or die(mysql_error());


header('location:index_successo.php');



    

}


?>
</body>
</html>

