<?php
session_start();
if (!isset($_SESSION['user'] ))
{
header("location:pagina_scaduta.php");
exit;
}
?>
