
<meta http-equiv="refresh" content="1">

<!DOCTYPE html>
<html>
	<body>
		<?php

			$pulse = file_get_contents("data.txt");
				
			print "<h1 style='text-align:center; font-size:40;'>Ardens' Heart Rate</h1>";
			print "<br>";
				
			print "<p style='text-align:center; font-size:200px; margin-top:85px; margin-bottom:10px; color='black';'>".$pulse."</p>";

		?>
	</body>
</html>


