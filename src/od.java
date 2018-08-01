import java.util.*;
import java.io.*;

class OD {
	public static void main(String[] args){
		for (int i = 0; i < args.length; ++i){
			if (args[i].equals("--help")) {
				System.out.println("Usage: od [OPTION]... [FILE]...");
			} else if (args[i].equals("--version")) {
				System.out.println("od (GNU coreutils) 8.25")
			}
		}
	}
}