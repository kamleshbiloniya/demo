extern crate fs_extra;
use fs_extra::dir::*;
use fs_extra::error::*;
use std::fs;
use std::env;

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    let cmd = &args[1];
    let flg = &args[2];
    let argc = args.len();
    let ln = "ln".to_string();
 

    println!("{} {}",flg,argc);

    if cmd == ln {
        // Ok();    
        // Err();
        println!("ok ln{} !",cmd);

    }

        match argc {
            5 => {
                println!("yeah! it's -r flag");
                let dir1 = &args[3];
                let dir2 = &args[4];
                println!("{} to {}",dir1,dir2);
                let options = fs_extra::dir::CopyOptions::new();
                // copy(dir1, dir2, &options);
            

            },
            _ => {
                println!("no -r flag!");
                let file1 = &args[2];
                let file2 = &args[3];
                println!("{} {}",file1,file2);

                fs::copy(file1, file2)?;  // Copy foo.txt to bar.txt
                // Ok();
            },
        }
        // fs::copy("src/foo.txt", "bar.txt")?;  // Copy foo.txt to bar.txt
        Ok(())
    


}