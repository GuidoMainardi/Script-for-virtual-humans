using System.Collections;
using System.Collections.Generic;
using System;
//using UnityEngine;

public class LeRoteiro //: MonoBehaviour
{
    public List<Agents> agentes = new List<Agents>();
    public Script script = new Script("script.txt");
    void main()
    {

        script.load();
        Console.WriteLine(script.ToString());  
 
    }
    // Start is called before the first frame update
    //void Start()
    //{
    //    script.load();
    //}

    // Update is called once per frame
    //void Update()
    //{
    //    
    //}

}

