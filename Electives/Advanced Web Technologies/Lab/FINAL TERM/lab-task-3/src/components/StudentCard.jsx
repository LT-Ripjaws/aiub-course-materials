import React from 'react'
import PropTypes from 'prop-types'
import CourseTag from './CourseTag'
import StatBadge from './StatBadge'
import { useStudents } from '../contexts/StudentContext'

function StudentCard({ name, id, avatar, gpa, major, courses }) {
  const { favorites, toggleFavorite, removeStudent } = useStudents()
  const isFavorite = favorites.has(id)

  return (
    <div className="student-card" data-testid="student-card">
      <img
        src={avatar}
        alt={name + "'s avatar"}
        className="student-card__avatar"
      />
      <div className="student-card__info">
        <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'flex-start' }}>
          <h3 className="student-card__name">{name}</h3>
          <div style={{ display: 'flex', gap: '6px' }}>
            <button
              onClick={() => toggleFavorite(id)}
              aria-label={isFavorite ? 'Remove from favorites' : 'Add to favorites'}
              style={{
                background: 'none',
                border: 'none',
                cursor: 'pointer',
                fontSize: '1.2rem',
                color: isFavorite ? '#ef4444' : '#9ca3af',
                transition: 'color 0.2s',
              }}
            >
              {isFavorite ? '❤️' : '🤍'}
            </button>
            <button
              onClick={() => removeStudent(id)}
              aria-label="Remove student"
              style={{
                background: 'none',
                border: 'none',
                cursor: 'pointer',
                fontSize: '1rem',
                color: '#9ca3af',
                transition: 'color 0.2s',
              }}
              title="Remove student"
            >
              🗑️
            </button>
          </div>
        </div>
        <p className="student-card__id">ID: {id}</p>
        <p className="student-card__major">Major: {major}</p>

        <div className="student-card__courses">
          {courses.map((course, index) => (
            <CourseTag
              key={index.toString()}
              courseName={course}
              color={index % 2 === 0 ? 'blue' : 'purple'}
            />
          ))}
        </div>

        <div className="student-card__stats">
          <StatBadge label="GPA" value={gpa.toFixed(2)} />
          <StatBadge label="Credits" value={90 + (parseInt(id.slice(-2)) || 0) % 20} />
        </div>
      </div>
    </div>
  )
}

StudentCard.propTypes = {
  name: PropTypes.string.isRequired,
  id: PropTypes.string.isRequired,
  avatar: PropTypes.string.isRequired,
  gpa: PropTypes.number.isRequired,
  major: PropTypes.string.isRequired,
  courses: PropTypes.arrayOf(PropTypes.string).isRequired,
}

export default StudentCard
