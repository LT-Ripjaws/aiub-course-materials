import React, { useState, useEffect } from 'react'
import { ThemeProvider, useTheme } from './contexts/ThemeContext'
import { StudentProvider, useStudents as useStudentContextInner } from './contexts/StudentContext'
import DashboardHeader from './components/DashboardHeader'
import StudentCard from './components/StudentCard'
import SearchBar from './components/SearchBar'
import SortControls from './components/SortControls'
import AddStudentForm from './components/AddStudentForm'
import './index.css'

function DashboardApp() {
  const { toggleTheme } = useTheme()
  const [showForm, setShowForm] = useState(false)
  const [notification, setNotification] = useState(null)

  useEffect(() => {
    if (!notification) return
    const timer = setTimeout(() => setNotification(null), 3000)
    return () => clearTimeout(timer)
  }, [notification])

  const handleAddStudent = (newStudent) => {
    setShowForm(false)
    const msg = '✅ Student ' + newStudent.name + ' added successfully!'
    setNotification({ message: msg, type: 'success' })
  }

  return (
    <div className="app">
      <DashboardHeader title="Student Dashboard" tagline="Track academic progress and course enrollments" />

      <main className="dashboard-grid" style={{ paddingTop: '2rem' }}>
        {!showForm && (
          <div style={{ gridColumn: '1 / -1', marginBottom: '16px' }}>
            <button
              onClick={() => setShowForm(true)}
              style={{
                padding: '12px 20px',
                fontSize: '1rem',
                fontWeight: 600,
                color: 'white',
                backgroundColor: 'var(--color-accent)',
                border: 'none',
                borderRadius: 'var(--radius-md)',
                cursor: 'pointer',
                boxShadow: '0 2px 8px rgba(16,185,129,0.35)',
              }}
            >
              + Add New Student
            </button>
          </div>
        )}

        {showForm && (
          <div style={{ gridColumn: '1 / -1' }}>
            <AddStudentForm onSuccess={handleAddStudent} onCancel={() => setShowForm(false)} />
          </div>
        )}

        {notification && (
          <div
            style={{
              position: 'fixed',
              top: '24px',
              right: '24px',
              padding: '12px 20px',
              backgroundColor: '#10b981',
              color: 'white',
              borderRadius: 'var(--radius-md)',
              boxShadow: '0 4px 12px rgba(0,0,0,0.15)',
              zIndex: 1000,
              fontSize: '0.95rem',
              fontWeight: 500,
            }}
          >
            {notification.message}
          </div>
        )}

        <StudentList />
      </main>

      <div
        style={{
          position: 'fixed',
          bottom: 0,
          left: 0,
          right: 0,
          backgroundColor: 'var(--color-surface)',
          borderTop: '1px solid var(--color-border)',
          padding: '16px 24px',
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          flexWrap: 'wrap',
          gap: '12px',
          boxShadow: '0 -2px 8px rgba(0,0,0,0.08)',
          zIndex: 100,
        }}
      >
        <SearchBar />
        <SortControls />
      </div>

      <div style={{ height: '120px' }} />
    </div>
  )
}

function StudentList() {
  const { displayedStudents } = useStudentContextInner()
  return (
    <>
      {displayedStudents.length === 0 ? (
        <div className="no-data" style={{ gridColumn: '1 / -1' }}>
          <div style={{ fontSize: '3rem', marginBottom: '1rem' }}>🔍</div>
          <h2>No students found</h2>
          <p>Try adjusting your search or add a new student.</p>
        </div>
      ) : (
        displayedStudents.map((student) => (
          <StudentCard key={student.id} {...student} />
        ))
      )}
    </>
  )
}

function App() {
  return (
    <ThemeProvider>
      <StudentProvider>
        <DashboardApp />
      </StudentProvider>
    </ThemeProvider>
  )
}

export default App
