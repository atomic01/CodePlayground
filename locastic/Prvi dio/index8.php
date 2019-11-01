<?php
// Write a function that passes through folders and prints
// files within each folder.

    $folder_name="Folder";

    function is_folder($file){

        $i=0;

        while(@$file[$i] != "" ){
            if($file[$i]=='.' )
                return false;
            $i++;
        }

        return true;
    } 

    function read_from_folder($folder_name){

        $fp = opendir ($folder_name);
        
        while(($file = readdir($fp)) != false ){

            if($file!='.' && $file!='..' && is_folder($file)==true){ 
                echo $file ."<br>";            
                read_from_folder($folder_name . "\\" . $file);            
            }
            elseif($file!='.' && $file!='..' && is_folder($file)!=true) 
                echo $file ."<br>";   
        }

        closedir($fp);
    }

    read_from_folder($folder_name);
?>