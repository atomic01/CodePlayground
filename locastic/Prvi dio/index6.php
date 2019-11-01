<?php

198/5000
// Write a function that receives as a parameter a series of integers and a number of groups.
// Divide that string into the specified number of groups so that it is the sum of all members
// within each group as close as possible.

//THIS ONE IS NOT FINSISHED, DOESNT WORK

    $niz_brojeva=[2, 1, 4, 7, 2, 1, 6, 8];
    $broj_grupa=3;
    $result;

    function sum($niz_brojeva){

        $sum=0;

        foreach($niz_brojeva as $i)
            $sum+=$i;

        return $sum;
    }

    function optimum_sum($niz_brojeva,$broj_grupa){

        $total_sum=sum($niz_brojeva);        
        $opt_sum=$total_sum/$broj_grupa;

        return (int)$opt_sum;
    }

    function find_max($niz_brojeva){

        $max=$niz_brojeva[0];

        foreach($niz_brojeva as $i)
            if($i > $max)
                $max=$i;

        return $max;
    }

    function my_sort($niz_brojeva){

        $max=find_max($niz_brojeva);
        $pom_niz;
        $sort_niz;
        $i=0;

        while($i<=$max){
            $pom_niz[]=0;
            $i++;
        }
        
        foreach($niz_brojeva as $x)
            $pom_niz[$x]++;
        
        for($i=$max;$i>=0;$i--)
            while($pom_niz[$i]>0){
                $sort_niz[]=$i;
                $pom_niz[$i]--;                
            }
        
        return $sort_niz;
    }

    function partition($niz_brojeva,$broj_grupa){

        $niz_brojeva=my_sort($niz_brojeva);
        $opt_sum=optimum_sum($niz_brojeva,$broj_grupa);
        $M;

        while($broj_grupa > 0){
            $M[$broj_grupa]=0;
            $broj_grupa--;
        }




    }
    
    $result=partition($niz_brojeva,$broj_grupa);
    //var_dump($result);
?>