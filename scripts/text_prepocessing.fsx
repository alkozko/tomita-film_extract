open System.IO
open System.Text.RegularExpressions

let inputFilePath = "./input/movies.txt"

let text = File.ReadAllText inputFilePath

let cleanedText = Regex.Replace(text, @"(«[^«»]+?)(\.)([^«»]+?»)", "$1,$3")

File.WriteAllText(inputFilePath, cleanedText)