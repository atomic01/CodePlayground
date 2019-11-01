<?php
// Write a function that receives a string as a parameter and returns a result
// the element that repeats itself most often within that string.

    $niz=[1, 5 ,6 ,7, 2 , 10, 12, 1 ,3 ,4 ,5, 1];
    $mostrepnumb=[];    

    function findmax($niz){

        $max=$niz[0];

        foreach ($niz as $i)
            if($i>$max)
                $max=$i;
                
        return $max;
    }                                       

    function findmaxreps($niz){

        $maxel=0;
        $mostrepnumb=[];
        $pniz=[];
        $i=0;
        $maxrep=0;

        $maxel=findmax($niz);
        while($i<=$maxel){
            $pniz[$i]=0;
            $i++;
        }                            
        
        foreach($niz as $j)
            $pniz[$j]++;             
        
        $maxrep=findmax($pniz);      
        
        $i=0;
        while($i<=$maxel){
            if($pniz[$i]==$maxrep)               
                $mostrepnumb[]=$i;
            
            $i++;
        }                            

        return $mostrepnumb;
    }

    $mostrepnumb=findmaxreps($niz);  
    echo "Most repeated numbers: ";
        foreach($mostrepnumb as $i)
            echo " $i ";
    echo "<br>";
?>