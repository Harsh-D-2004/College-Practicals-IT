package com.prj.service;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import com.prj.entity.Student;

public class FileHandling {
	
	private String fileName;
	
	public FileHandling() {
		
		this.fileName = "default.txt";
	}
	
	
	public void createDatabase() {
		
		Scanner sobj = new Scanner(System.in);
		
		 try {  
			 
			 System.out.println("Enter Name of Database : ");
			 fileName = sobj.next();
          
             File f0 = new File(fileName);   
             if (f0.createNewFile()) {  
                        System.out.println("File " + f0.getName() + " is created successfully.");  
             } else {  
                        System.out.println("File is already exist in the directory.");  
             }  
           } catch (IOException exception) {  
                    System.out.println("An unexpected error is occurred.");  
                    exception.printStackTrace();  
        }   
	}
	
	public void writeToDatabase() {
	    try {  
	    	
	    	Student obj = new Student();
	    	obj.getData();
	    	
	        FileWriter fwrite = new FileWriter(fileName);  

	        fwrite.write(obj.displayData());   
	    
	        fwrite.close();   
	        
	        System.out.println("Content is successfully wrote to the file.");  
	        
	    } catch (IOException e) {  
	    	
	        System.out.println("Unexpected error occurred");  
	        e.printStackTrace();  
	        
	        }  
	}
	
	public void readDatabase() {
        try {  

            File f1 = new File(fileName);    
            
            Scanner dataReader = new Scanner(f1);  
            
            while (dataReader.hasNextLine()) {  
                String fileData = dataReader.nextLine();  
                System.out.println(fileData);  
            } 
            
            dataReader.close();  
        } catch (FileNotFoundException exception) {  
            System.out.println("Unexcpected error occurred!");  
            exception.printStackTrace();  
        }  
	}
	
	
	public void deleteDatabase() {
		
	    File f0 = new File(fileName); 
	    
	    if (f0.delete()) {   
	      System.out.println(f0.getName()+ " file is deleted successfully.");  
	    } 
	    
	    else {  
	      System.out.println("Unexpected error found in deletion of the file.");  
	    }   
	}
	
	public void updateDatabase() {
		
	}
	
	
}
