<?php
// Write a function that receives a number of integers as a parameter,
// a returns the smallest number within that string as a result

    $niz=[10,2,3,4,1,6,5,8];

    function findmin($niz){

        $min=$niz[0];

        foreach ($niz as $i)
            if($i<$min)
                $min=$i;

        return $min;
    }

   echo "Smallest member is: " . findmin($niz);  
?>