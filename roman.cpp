string Solution::intToRoman(int A) {
    string s="";
    while(A !=0){
        if(A>=1000){
            A -=1000;
            s += "M";
        }
        else if(A>=900){
            A -= 900;
            s += "CM";
        }
        else if(A>=500){
            A -= 500;
            s += "D";
        }
        else if(A>=400){
            A -= 400;
            s += "CD";
        }
        else if(A>=100){
            A -=100;
            s += "C";
        }
        else if(A>=90){
            A -= 90;
            s += "XC";
        }
        else if(A>=50){
            A -= 50;
            s +="L";
        }
        else if(A>=40){
            A -= 40;
            s+= "XL";
        }
        else if(A>=10){
            A -= 10;
            s += "X";
        }
        else if(A>=9){
            A -= 9;
            s += "IX";
        }
        else if(A>=5){
            A -= 5;
            s += "V";
        }
        else if(A>=4){
            A -= 4;
            s += "IV";
        }
        else if(A>=1){
            s +="I";
        }
    }
    return s;
}
