<?php
// $ Write a function that receives a string as a parameter and returns a result
// true if the default string is a palindrome. Otherwise it returns false.
    
    $word = "anavolimilovana";
    $is_pal=FALSE;

    function my_str_len($str){

        $i=0;

        while(@$str[$i]!= "")
            $i++;

        return $i;
    }

    function is_palindrom($word){
        
        $word_len=0;
        $reverse_word="";
                
        $word_len=my_str_len($word);              

        while($word_len > 0){
            $reverse_word.=$word[$word_len-1];
            $word_len--;
        }                                        
		
		if($reverse_word==$word)
			return TRUE;
		 else
            return FALSE;        
    }
    
    echo "$word--(is_polindrom?)-->";
    $is_pal=is_palindrom($word);
    
    if($is_pal==TRUE)
        echo " TRUE";
    else
        echo " FALSE";          
?>