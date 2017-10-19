
protocol Classify{
    func isStudent() -> Bool
}

enum Subject{
    case Math
    case English
    case French
    case History
}

class Person{
    var first_name: String
    var last_name: String
    var age: Int
    
    init(first_name: String, last_name: String, age: Int){
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
    }
    
    func fullName() -> String{
        return self.first_name + " " + self.last_name
    }
    
}

class Mentor: Person, Classify {
    let subject: Subject
    
    init(first_name: String, last_name: String, age: Int, subject: Subject = Subject.Math){
        self.subject = subject
        super.init(first_name: first_name, last_name: last_name, age: age)
    }
    
    func isStudent() -> Bool {
        return false
    }
    
    func stringSubject() -> String {
        switch self.subject {
        case .Math:
            return "Math"
        case .English:
            return "English"
        case .French:
            return "French"
        case .History:
            return "History"
        }
    }
}

class Student: Person, Classify {
    func isStudent() -> Bool {
        return true
    }
}

class School {
    var name: String
    var list_persons = [Person]()
    
    init(name: String) {
        self.name = name
    }
    
    func addStudent(p: Person) -> Bool {
        if p is Student {
            list_persons.append(p)
            return true
        }
        return false
    }
    
    func addMentor(p: Person) -> Bool {
        if p is Mentor {
            list_persons.append(p)
            return true
        }
        return false
    }
    
    func listStudents() -> [Person] {
        return ((list_persons.filter{ $0 is Student }).sort{ $0.age > $1.age })
    }
    
    func listMentors() -> [Person] {
        return ((list_persons.filter{ $0 is Mentor }).sort{ $0.age > $1.age })
    }
    
    //func listMentorsBySubject(subject: Subject) -> [Person] {
        //return((list_persons.filter{ $0.subject == subject }).filter{ $0 is Mentor })
        //return (((list_persons.filter{ $0 is Mentor }).filter{ $0.subject == subject }).sort{ $0.age > $1.age })
    //}
    
}

var s = Student(first_name: "Sam", last_name: "Scoth", age: 20)
var m = Mentor(first_name: "Alex", last_name: "Rap", age: 34, subject: Subject.French)
var m2 = Mentor(first_name: "Gus", last_name: "Fring", age: 54, subject: Subject.English)
var m3 = Mentor(first_name: "Walter", last_name: "White", age: 52, subject: Subject.Math)


var school = School(name: "Holberton")
school.addStudent(s)
school.addMentor(m)
school.addMentor(m2)
school.addMentor(m3)








