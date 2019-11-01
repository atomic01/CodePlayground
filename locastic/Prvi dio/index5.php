<?php


// Write a function that receives two strings (strings) and returns the longest
// common string (substring).

    $string1="morskikonjic";
    $string2="zmajkonja";
    $string_rez="";

    function my_str_len($string){

        $i=0;

        while(@$string[$i]!= "")
            $i++;

         return $i;
    } 
    function str_to_array($string){

        $string_len=0;
        $array=[];
        $i=0;
                
        $string_len=my_str_len($string); 

        while($i<$string_len){
            $array[]=$string[$i];
            $i++;
        }

        return $array;
    } 
    
    function array_to_string($array){

        foreach($array as $c)
            $string.=$c;
        
        return $string;
    } 

    function longest_common_substring($string1,$string2){
        $array1=str_to_array($string1);
        $array2=str_to_array($string2);
        $help_matrix;
        $i=$j=0;
        $max =0;
        $last_common_index=0;
        $first_common_index=0;
        $sub_string="";

        for($i=0; $i < my_str_len($string1) ; $i++){
            for($j ; $j < my_str_len($string2) ; $j++){
                $help_matrix[$i][$j]=0;
            }
            $j=0;
        }
        
        for($i=0; $i < my_str_len($string1) ; $i++){
            for($j=0; $j < my_str_len($string2) ; $j++){
                if($array1[$i]==$array2[$j])
                {
                    if($i==0 || $j==0)
                        $help_matrix[$i][$j]++;
                    else
                        $help_matrix[$i][$j]=$help_matrix[$i-1][$j-1] + 1;

                    if($help_matrix[$i][$j]>$max)
                        $max=$help_matrix[$i][$j];
                }               
            }
        }

        for($i=0; $i < my_str_len($string1) ; $i++){
            for($j=0; $j <my_str_len($string2) ; $j++){
                if($help_matrix[$i][$j]==$max)
                    $last_common_index=$i;   
                }   
        }

        $first_common_index = $last_common_index-$max + 1;
        while($first_common_index <= $last_common_index){
            $sub_string.= $array1[$first_common_index];
            $first_common_index++;           
        }  

        return $sub_string;
    }

    $string_rez=longest_common_substring($string1,$string2);
    echo"LCS ( $string1 , $string2 ) ----> $string_rez";    
?>