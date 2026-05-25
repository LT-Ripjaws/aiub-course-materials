import React from 'react'
import DashboardHeader from './components/DashboardHeader'
import StudentCard from './components/StudentCard'
import './index.css'

const students = [
  {
    id: 'STD001',
    name: 'Alice Chen',
    gpa: 3.85,
    major: 'Computer Science',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Alice',
    courses: ['React Fundamentals', 'Data Structures', 'Algorithms'],
  },
  {
    id: 'STD002',
    name: 'Bob Martinez',
    gpa: 3.42,
    major: 'Software Engineering',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Bob',
    courses: ['Web Development', 'Database Systems', 'Software Design'],
  },
  {
    id: 'STD003',
    name: 'Carol Zhang',
    gpa: 3.96,
    major: 'Information Systems',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=Carol',
    courses: ['Business Analytics', 'Project Management', 'Cloud Computing'],
  },
  {
    id: 'STD004',
    name: 'David Kim',
    gpa: 3.71,
    major: 'Cybersecurity',
    avatar: 'https://api.dicebear.com/7.x/avataaars/svg?seed=David',
    courses: ['Network Security', 'Cryptography', 'Ethical Hacking'],
  },
]

function App() {
  return (
    <div className="app">
      <DashboardHeader title="Student Dashboard" tagline="Track academic progress and course enrollments" />
      <main className="dashboard-grid">
        {students.map((student) => (
          <StudentCard
            key={student.id}
            name={student.name}
            id={student.id}
            avatar={student.avatar}
            gpa={student.gpa}
            major={student.major}
            courses={student.courses}
          />
        ))}
      </main>
    </div>
  )
}

export default App
