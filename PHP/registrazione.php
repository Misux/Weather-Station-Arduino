<html>
<head>
<title>Registrazione</title>
</head>
<style>
body{
	background-image:url('sky.jpg');
	
}</style>
<body>

<p align="center"><font face="verdana" size="15" color="white"> Registrazione Utente </font><br><br>
	<title > Stazione Meteo </title>
<form method=POST action="registrazionedb.php">
     
    
<p align="center"> 
Username:<br>         
            <input name=username type=username size=15>
<br>
Password:<br>
            <input name=password type=password size=15>
<br>
Nome:<br>
            <input name=nome type=text size=15>
<br>
Cognome:<br>
            <input name=cognome type=text size=15>
<br>
Codice Fiscale:<br>
            <input name=codice_fiscale type=text size=15>
<br>
Telefono:<br>
            <input name=telefono type=text size=15>
<br>
E-mail:<br>
            <input name=email type=text size=15>

<br><br>


            <input name="submit" type=submit value=Registrati>
	    <INPUT TYPE="button" VALUE="Annulla" onClick="window.location.href='index.php'"> </FORM></p>
	    <p align="center"><INPUT TYPE="button" VALUE="Esci" onClick="window.location.href='logout.php'"> </FORM></p>
</f



</form>
</body>
</html> 



