import React, { useState } from 'react'
import PropTypes from 'prop-types'
import { useStudents } from '../contexts/StudentContext'

function AddStudentForm({ onSuccess, onCancel }) {
  const { addStudent } = useStudents()

  const [formData, setFormData] = useState({
    name: '',
    id: '',
    major: '',
    gpa: '',
    courses: '',
  })
  const [errors, setErrors] = useState({})
  const [touched, setTouched] = useState({})

  const validateField = (name, value) => {
    switch (name) {
      case 'name':
        if (!value.trim()) return 'Name is required'
        if (value.trim().length < 2) return 'Name must be at least 2 characters'
        return ''
      case 'id':
        if (!value.trim()) return 'Student ID is required'
        if (!/^\d+$/.test(value)) return 'ID must be numeric'
        return ''
      case 'major':
        if (!value.trim()) return 'Major is required'
        return ''
      case 'gpa':
        if (!value) return 'GPA is required'
        const gpaNum = parseFloat(value)
        if (isNaN(gpaNum)) return 'GPA must be a number'
        if (gpaNum < 0 || gpaNum > 4.0) return 'GPA must be between 0 and 4.0'
        return ''
      case 'courses':
        if (!value.trim()) return 'At least one course is required'
        if (value.split(',').some(c => !c.trim())) return 'Course names cannot be empty'
        return ''
      default:
        return ''
    }
  }

  const handleChange = (e) => {
    const { name, value } = e.target
    setFormData(prev => ({ ...prev, [name]: value }))
    if (touched[name]) {
      setErrors(prev => ({ ...prev, [name]: validateField(name, value) }))
    }
  }

  const handleBlur = (e) => {
    const { name, value } = e.target
    setTouched(prev => ({ ...prev, [name]: true }))
    setErrors(prev => ({ ...prev, [name]: validateField(name, value) }))
  }

  const handleSubmit = (e) => {
    e.preventDefault()

    const newErrors = {}
    Object.keys(formData).forEach(key => {
      const err = validateField(key, formData[key])
      if (err) newErrors[key] = err
    })
    setErrors(newErrors)
    setTouched({ id: true, name: true, major: true, gpa: true, courses: true })

    if (Object.keys(newErrors).length > 0) return

    const avatarUrl = 'https://api.dicebear.com/7.x/avataaars/svg?seed=' + encodeURIComponent(formData.name.trim())
    const newStudent = {
      id: formData.id.toUpperCase(),
      name: formData.name.trim(),
      major: formData.major.trim(),
      gpa: parseFloat(formData.gpa),
      avatar: avatarUrl,
      courses: formData.courses.split(',').map(c => c.trim()).filter(Boolean),
    }

    addStudent(newStudent)
    if (onSuccess) onSuccess(newStudent)
    if (onCancel) onCancel()
  }

  const inputStyle = { width: '100%', padding: '10px 12px', fontSize: '0.95rem', border: '1px solid var(--color-border)', borderRadius: 'var(--radius-sm)', marginBottom: '6px', outline: 'none' }
  const errorStyle = { color: '#ef4444', fontSize: '0.8rem', marginBottom: '12px', minHeight: '1.2em' }
  const labelStyle = { display: 'block', marginBottom: '4px', fontWeight: 500, fontSize: '0.9rem' }

  return (
    <form onSubmit={handleSubmit} style={{
      backgroundColor: 'var(--color-surface)',
      padding: '24px',
      borderRadius: 'var(--radius-md)',
      boxShadow: '0 4px 12px rgba(0,0,0,0.1)',
      marginBottom: '24px',
    }}>
      <h3 style={{ marginBottom: '16px' }}>Add New Student</h3>
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(200px, 1fr))', gap: '16px' }}>
        <div>
          <label style={labelStyle}>Full Name *</label>
          <input name="name" value={formData.name} onChange={handleChange} onBlur={handleBlur} style={inputStyle} placeholder="e.g. John Doe" />
          {errors.name && <div style={errorStyle}>{errors.name}</div>}
        </div>
        <div>
          <label style={labelStyle}>Student ID *</label>
          <input name="id" value={formData.id} onChange={handleChange} onBlur={handleBlur} style={inputStyle} placeholder="e.g. STD005" />
          {errors.id && <div style={errorStyle}>{errors.id}</div>}
        </div>
        <div>
          <label style={labelStyle}>Major *</label>
          <input name="major" value={formData.major} onChange={handleChange} onBlur={handleBlur} style={inputStyle} placeholder="e.g. Computer Science" />
          {errors.major && <div style={errorStyle}>{errors.major}</div>}
        </div>
        <div>
          <label style={labelStyle}>GPA (0–4.0) *</label>
          <input name="gpa" type="number" step="0.01" min="0" max="4.0" value={formData.gpa} onChange={handleChange} onBlur={handleBlur} style={inputStyle} placeholder="e.g. 3.75" />
          {errors.gpa && <div style={errorStyle}>{errors.gpa}</div>}
        </div>
        <div style={{ gridColumn: '1 / -1' }}>
          <label style={labelStyle}>Courses (comma-separated) *</label>
          <input name="courses" value={formData.courses} onChange={handleChange} onBlur={handleBlur} style={{ ...inputStyle, width: '100%' }} placeholder="e.g. React, Node.js, TypeScript" />
          {errors.courses && <div style={errorStyle}>{errors.courses}</div>}
        </div>
      </div>
      <div style={{ display: 'flex', gap: '12px', marginTop: '16px' }}>
        <button type="submit" style={{ padding: '10px 24px', fontSize: '0.95rem', fontWeight: 600, color: 'white', backgroundColor: 'var(--color-primary)', border: 'none', borderRadius: 'var(--radius-sm)', cursor: 'pointer' }}>
          Add Student
        </button>
        <button type="button" onClick={onCancel} style={{ padding: '10px 24px', fontSize: '0.95rem', fontWeight: 500, color: 'var(--color-text)', backgroundColor: 'var(--color-bg)', border: '1px solid var(--color-border)', borderRadius: 'var(--radius-sm)', cursor: 'pointer' }}>
          Cancel
        </button>
      </div>
    </form>
  )
}

AddStudentForm.propTypes = {
  onSuccess: PropTypes.func,
  onCancel: PropTypes.func.isRequired,
}
export default AddStudentForm
