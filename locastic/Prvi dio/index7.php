<?php
// Write a function that prints numbers from 1 to 100, but so that for
// numbers that are divisible by 3 prints "LOCA", for numbers that are divisible
// with 5 print "STIC", and print "Locastic" for numbers  divisible with numbers 3 and 5


    function ispis(){

        for($i=1;$i<100;$i++){
            echo "$i--->";
            if($i%3==0)
                echo "LOCA";

            else if($i%5==0)
                echo "STIC";

            else if($i%15!=0)
                echo "No value";

            echo "<br>";    
        }
    }

    ispis();
?>