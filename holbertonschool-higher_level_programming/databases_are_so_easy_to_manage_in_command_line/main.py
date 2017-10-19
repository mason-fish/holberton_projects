from sys import argv
from models import *
from peewee import *
import json

''' main function, routes commands to the appropriate function '''
def main():

    my_models_db.connect()

    if len(argv) < 2:
        print "Please enter an action"
        return

    actions = (
        "create",
        "print",
        "insert",
        "delete",
        "print_batch_by_school",
        "print_student_by_batch",
        "print_student_by_school",
        "print_family",
        "age_average",
        "change_batch",
        "print_all",
        "note_average_by_student",
        "note_average_by_batch",
        "note_average_by_school",
        "top_batch",
        "top_school",
        "import_json",
        "export_json"
    )

    ''' check if not an action '''
    if argv[1] not in actions:
        print "Undefined action <first argument value>"
        return

    run_function = "action_" + argv[1]
    eval(run_function)(argv)

''' helper function for checking if model exists and returns proper
    coresponding name if it does, simply by capitalizing the first
    letter, as that is the pre-defined convention. '''
def check_mod(cmd):
    mod_list = (
        "school",
        "batch",
        "student",
        "exercise"
    )

    if cmd in mod_list:
        return cmd.title()

    return False

''' the action for inserting into the database '''
def action_insert(argv):
    if len(argv) <= 2:
        return

    if argv[2] == "school":
        try:
            x = School.create(name=argv[3])
        except peewee.OperationalError:
            pass
        print "New School: %s" % (x)
        return

    if argv[2] == "batch":
        try:
            x = Batch.create(school=argv[3], name=argv[4])
        except peewee.OperationalError:
            pass
        print "New Batch: %s" % (x)
        return

    if argv[2] == "student":
        try:
            args = [
                'batch',
                'age',
                'last_name',
                'first_name',
                ]

            options = {}

            i = 3
            for op in args:
                if i < len(argv):
                    if op is "age":
                        options[op] = int(argv[i])
                        i += 1
                        continue
                    options[op] = str(argv[i])
                    i += 1

            new = Student.create(**options)
        except peewee.OperationalError:
            pass
        print "New Student: %s" % (new)
        return

    if argv[2] == "exercise":
        if len(argv) != 6:
            print "Wrong amount of arguments"
            return

        try:
            x = Exercise.create(student=argv[3], subject=argv[4], note=argv[5])
        except peewee.OperationalError:
            pass
        print "New Exercise: %s" % (x)
        return



''' the action for deleting a record from the database '''
def action_delete(argv):
    if len(argv) != 4:
        return

    tmp = check_mod(argv[2])
    if tmp is False:
        print "Nothing to delete"
        return

    tmp = eval(tmp)
    try:
        x = tmp.get(tmp.id == argv[3])
    except:
        print "Nothing to delete"
        return

    x.delete_instance()
    print "Delete: %s" % (x)

''' the action for printing out a table of the database '''
def action_print(argv):
    if len(argv) != 3:
        return

    tmp = check_mod(argv[2])

    if tmp is False:
        print "Table does not exist in database"
        return

    group = eval(tmp).select()
    for i in group:
        print i

''' the action to create all schemas for each databse table '''
def action_create(argv):
    try:
        my_models_db.create_tables([School, Batch, User, Student, Exercise], safe=True)
    except peewee.OperationalError:
        pass



''' action to print all batches related to a given school '''
def action_print_batch_by_school(argv):
    if len(argv) != 3:
        print "Wrong amount of arguments"
        return

    try:
        x = School.get(School.id == argv[2])
    except:
        print "School not found"
        return

    tmp = Batch.select().where(Batch.school == x.id)
    for i in tmp:
        print i

''' action to print all students in a specified batch '''
def action_print_student_by_batch(argv):
    if len(argv) != 3:
        print "Wrong amount of arguments"
        return

    try:
        x = Batch.get(Batch.id == argv[2])
    except:
        print "Batch not found"
        return

    tmp = Student.select().where(Student.batch == x.id)
    for i in tmp:
        print i

''' action to print all students in a specified school '''
def action_print_student_by_school(argv):
    if len(argv) != 3:
        print "Wrong amount of arguments"
        return

    try:
        x = School.get(School.id == argv[2])
    except:
        print "School not found"
        return

    tmp = Student.select().join(Batch).where(Student.batch == Batch.id, Batch.school == x.id)
    for i in tmp:
        print i

''' action to print all students with the same last name '''
def action_print_family(argv):
    if len(argv) != 3:
        print "Wrong amount of arguments"
        return

    tmp = Student.select().where(Student.last_name == argv[2])
    for i in tmp:
        print i

''' action to print the average age of all students or, if specified,
    the average age of all students within a given batch '''
def action_age_average(argv):
    if len(argv) == 3:
        try:
            x = Batch.get(Batch.id == argv[2])
        except Batch.DoesNotExist:
            print "Batch not found"
            return

        x = Student.select(fn.SUM(Student.age)).where(Student.batch == argv[2]).scalar()
        y = Student.select(fn.COUNT()).where(Student.batch == argv[2]).scalar()
        print x / y
        return

    if len(argv) != 2:
        print "Wrong amount of arguments"
        return

    x = Student.select(fn.SUM(Student.age)).scalar()
    y = Student.select(fn.COUNT()).scalar()
    print x / y


''' action to change a specified student from its current batch to a
    different specified batch '''
def action_change_batch(argv):
    if len(argv) != 4:
        print "Wrong amount of arguments"
        return

    try:
        x = Student.get(Student.id == argv[2])
        y = Batch.get(Batch.id == argv[3])

    except Student.DoesNotExist:
        print "Student not found"
        return

    except Batch.DoesNotExist:
        print "Batch not found"
        return

    if Student.select().where(Student.id == argv[2], Student.batch == argv[3]).exists():
        print "%s already in %s" % (x, y)
        return

    print "%s had been move to %s" % (x, y)
    print x
    x.batch = argv[3]
    x.save()

''' action to print all students, batches, and schools in a tree presentation'''
def action_print_all(argv):
    sch = School.select()
    for sch_i in sch:
        print sch_i
        bat = Batch.select().where(Batch.school == sch_i.id)
        for bat_i in bat:
            print "\t", bat_i
            stu = Student.select().join(Batch).where(Batch.school == sch_i.id, Student.batch == bat_i.id)
            for stu_i in stu:
                    print "\t\t", stu_i
                    exr = Exercise.select().where(Exercise.student == stu_i.id)
                    for exr_i in exr:
                        print "\t\t\t", exr_i

def action_note_average_by_student(argv):
    if len(argv) != 3:
        return

    try:
        tmp = Student.get(Student.id == argv[2])
    except Student.DoesNotExist:
        print "Student not found"
        return

    sub = Exercise.select().where(Exercise.student == argv[2]).group_by(Exercise.subject)
    for sub_i in sub:
        x = Exercise.select(fn.SUM(Exercise.note)).where(Exercise.student == argv[2], Exercise.subject == sub_i.subject).scalar()
        y = Exercise.select(fn.COUNT(Exercise.note)).where(Exercise.student == argv[2], Exercise.subject == sub_i.subject).scalar()
        print "%s: %d" % (sub_i.subject, (x / y))

def action_note_average_by_batch(argv):
    if len(argv) != 3:
        return

    try:
        tmp = Batch.get(Batch.id == argv[2])
    except Batch.DoesNotExist:
        print "Batch not found"
        return

    sub = Exercise.select(Exercise.subject).join(Student).where(Student.batch == argv[2]).group_by(Exercise.subject)

    for sub_i in sub:
        tmp = sub.select(fn.SUM(Exercise.note)).where(Exercise.subject == sub_i.subject).scalar()
        count = Exercise.select(fn.COUNT(Exercise.note)).join(Student, on=Exercise.student).where(Student.batch == argv[2], Exercise.subject == sub_i.subject).scalar()
        print "%s: %s" % (sub_i.subject, (tmp / count))


def action_note_average_by_school(argv):
    if len(argv) != 3:
        return

    try:
        tmp = School.get(School.id == argv[2])
    except School.DoesNotExist:
        print "School not found"
        return

    sub = (Exercise
        .select(Exercise.subject)
        .join(Student, on=Exercise.student)
        .join(Batch, on=Student.batch)
        .where(Batch.school == argv[2])
        .group_by(Exercise.subject))

    for sub_i in sub:
        tmp = sub.select(fn.Avg(Exercise.note)).where(Exercise.subject == sub_i.subject).scalar()
        print "%s: %d" % (sub_i.subject, int(tmp))

def action_top_batch(argv):
    if 5 > len(argv) < 3:
        print "Wrong amount of arguments"

    try:
        tmp = Batch.get(Batch.id == argv[2])
    except Batch.DoesNotExist:
        print "Batch not found"
        return

    if len(argv) == 4:

        base = (Exercise
            .select()
            .join(Student, on=Exercise.student)
            .join(Batch, on=Student.batch)
            .where(Batch.id == argv[2], Exercise.subject == argv[3])
        )

        agg = (base
            .select(Student, Exercise, fn.Avg(Exercise.note).alias('sub_avg'))
            .group_by(Student)
            .order_by(-fn.Avg(Exercise.note))
        )

        if not agg:
            print "No results"
            return

        print agg[0].student

    else:

        base = (Exercise
            .select()
            .join(Student, on=Exercise.student)
            .join(Batch, on=Student.batch)
            .where(Batch.id == argv[2])
        )

        agg = (base
            .select(Student, Exercise, fn.Avg(Exercise.note).alias('sub_avg'))
            .group_by(Student)
            .order_by(-fn.Avg(Exercise.note))
        )

        if not agg:
            print "No results"
            return

        print agg[0].student


def action_top_school(argv):
    if 5 > len(argv) < 3:
        print "Wrong amount of arguments"

    try:
        tmp = School.get(School.id == argv[2])
    except School.DoesNotExist:
        print "Batch not found"
        return

    if len(argv) == 4:

        base = (Exercise
            .select()
            .join(Student, on=Exercise.student)
            .join(Batch, on=Student.batch)
            .join(School, on=Batch.school)
            .where(School.id == argv[2], Exercise.subject == argv[3])
        )

        agg = (base
            .select(Student, Exercise, School, fn.Avg(Exercise.note))
            .group_by(Student)
            .order_by(-fn.Avg(Exercise.note))
        )

        if not agg:
            print "No results"
            return

        print agg[0].student

    else:

        base = (Exercise
            .select()
            .join(Student, on=Exercise.student)
            .join(Batch, on=Student.batch)
            .join(School, on=Batch.school)
            .where(School.id == argv[2])
        )

        agg = (base
            .select(Student, Exercise, fn.Avg(Exercise.note))
            .group_by(Student)
            .order_by(-fn.Avg(Exercise.note))
        )

        if not agg:
            print "No results"
            return

        print agg[0].student

def action_import_json(argv):

    if len(argv) != 3:
        print "Wrong amount of arguments"
        return

    json_string = argv[2]

    try:
        new_dict = json.loads(json_string)
    except ValueError:
        print "Please set a JSON string"
        return

    for school in new_dict:
        new_school = school['name']
        action_insert([None, None, "school", new_school])
        school_id = School.get(School.name == new_school)
        for batch in school['batches']:
            new_batch = batch['name']
            action_insert([None, None, "batch", school_id.id, new_batch])
            batch_id = Batch.get(Batch.name == new_batch)
            for student in batch['students']:
                new_student = [
                    None,
                    None,
                    "student",
                    batch_id.id,
                    int(student['age']),
                    str(student['last_name']),
                    str(student['first_name'])
                ]
                action_insert(new_student)
                student_id = Student.get(Student.first_name == student['first_name'], Student.last_name == student['last_name'])
                for exercise in student['exercises']:
                    new_exercise = [
                        None,
                        None,
                        "exercise",
                        student_id.id,
                        str(exercise['subject']),
                        int(exercise['note'])
                    ]
                    action_insert(new_exercise)


def action_export_json(argv):
    if len(argv) != 2:
        print "Wrong amount of arguments"
        return

    full_json = []

    sch = School.select()
    for sch_i in sch:
        new_sch = {}
        new_sch['name'] = str(sch_i.name)
        bat = Batch.select().where(Batch.school == sch_i.id)
        new_sch['batches'] = []

        for bat_i in bat:
            new_bat = {}
            new_bat['name'] = str(bat_i.name)
            stu = Student.select().join(Batch).where(Batch.school == sch_i.id, Student.batch == bat_i.id)
            new_bat['students'] = []

            for stu_i in stu:
                new_stu = {}
                new_stu['first_name'] = str(stu_i.first_name)
                new_stu['last_name'] = str(stu_i.last_name)
                new_stu['age'] = int(stu_i.age)
                exr = Exercise.select().where(Exercise.student == stu_i.id)
                new_stu['exercises'] = []

                for exr_i in exr:
                    new_exr = {}
                    new_exr['subject'] = str(exr_i.subject)
                    new_exr['note'] = int(exr_i.note)

                    new_stu['exercises'].append(new_exr)

                new_bat['students'].append(new_stu)
            new_sch['batches'].append(new_bat)
        full_json.append(new_sch)

    print json.dumps(full_json)


''' end of main '''
if __name__ == "__main__":
    main()
