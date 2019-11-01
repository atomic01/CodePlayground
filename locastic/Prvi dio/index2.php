<?php
// Write a function that receives two integer parameters
// n and m, and returns n ^ m as a result.

	$base=2;
	$exp=5;
	$result=0;

	function to_the_power($base, $exp){

		$result = $base ** $exp;

		return $result;
	}

	$result = to_the_power($base, $exp);
	echo "$base ^ $exp = $result";	
?>


