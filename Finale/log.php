<?php


include ("dbconnect.php"); //includi i paramentri database dati in precedenza


	
	
         $user= $_POST['user']; // riceve user e pass dalla pagina precedente e le mette in quelle variabili

         $pass= $_POST['pass'];

	$query = "SELECT * from utenti WHERE username = '$user' AND password = '$pass'"; // seleziona e controlla  l'utente con 													quella pass e quello  user 

   	$risultato = mysql_query($query); // è una funzione che esegue la query e restituisce uno 0 o 1 a seconda se ha trovato l'utente

   	$trovato = mysql_num_rows($risultato); // mi restituisce il num di righe dell'utente della query

     

   if($trovato) //se ha trovato(vero) il num righe quindi i campi

   {
	session_start();
   	$_SESSION['user']=$user;
    header("location: visualizza.php"); // l'utente è stato riconosciuto e vai a loggato se funziona
    exit;

   }

   else

   {

    header("location: non.php");
    
   }

?>








